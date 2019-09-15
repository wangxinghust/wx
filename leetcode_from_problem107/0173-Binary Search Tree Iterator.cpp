#include <stack>
using namespace std;

// ˼·һ ����ת��Ϊvector��hasNext���ǿ��±��Ƿ񼴽�Խ�缴�ɣ�����������Ŀ�Ŀռ临�Ӷ�Ҫ��


// ˼·��������stack���ݴ游�ڵ��ֵ�����Ҳ����ҽڵ��ʱ�򣬾�ȥȡ���ڵ��ֵ

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
				// �ڱ�����ʱ��Ҫ���˽����ڵ���뵽ջ�����ᱨ��ģ����߽����������ȡ�������ֱ����
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
		return curr != nullptr; // nullptr���жϺܷ�ʱ�䣬���ǱȽϷ���C11���ԣ����Ƕ���nullptr�ĺ�
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