#include <stack>
using namespace std;

// 思路一 将树转化为vector，hasNext就是看下标是否即将越界即可，但不满足题目的空间复杂度要求


// 思路二，利用stack来暂存父节点的值，当找不到右节点的时候，就去取父节点的值

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		curr = root;
		while (curr && curr->left) {
			parent.push(curr);
			curr = curr->left;
		}
	}

	/** @return the next smallest number */
	int next() {
		int res = curr->val;
		if (curr->right) {
			curr = curr->right;
			while (curr->left) {
				// 在遍历的时候不要忘了将父节点加入到栈里，否则会报错的，或者将这个函数提取出来，分别调用
				parent.push(curr);
				curr = curr->left;
			}
		} else if (!parent.empty()) {
			curr = parent.top();
			parent.pop();
		} else {
			curr = nullptr;
		}
		return res;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return curr != nullptr; // nullptr的判断很费时间，但是比较符合C11特性，还是多用nullptr的好
	}
private:
	stack<TreeNode*> parent;
	TreeNode* curr;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */