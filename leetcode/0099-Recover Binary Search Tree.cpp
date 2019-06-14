#include <stack>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) {
		val = x;
		left = nullptr;
		right = nullptr;
	}
};

class Solution {
public:
	//思路：中序遍历，找两次比前面数小的，被交换的两个结点，一个是第一次找到的结点前一个，另一个是第二次找到的当前结点
	//技巧：第一次找到时，将前一结点的值赋值给first，将当前结点赋值给secon，避免只能找到一次（相邻结点做交换时）
	//Runtime: 16 ms, faster than 99.01% of C++ online submissions for Recover Binary Search Tree.
	//Memory Usage : 19.4 MB, less than 43.25 % of C++ online submissions for Recover Binary Search Tree.
	void recoverTree(TreeNode* root) {
		if (!root) return;
		TreeNode* first = nullptr, * second = nullptr;

		stack<TreeNode*> s;
		TreeNode* p = root;
		TreeNode* prev = nullptr;
		int current;
		bool isFirst = true, next = false;
		while (p || !s.empty()) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			if (!s.empty()) {
				p = s.top();

				if (!isFirst) {
					if (p->val <= current) {
						//第一次找到小于前面的数，将前一结点prev赋给first
						if (!next) {
							//C4703 使用了可能未初始化的本地指针变量
							if (prev) {
								first = prev;
								//此处赋值是避免相邻结点交换的情况，在第二次找到小于前面的数时，会再次更新second
								second = p;
							}
							next = true;
						}
						//第二次找到小于前面的数，将当前结点的值赋给second
						else {
							second = p;
						}
					}

				}
				else {
					prev = p;
					current = p->val;
					isFirst = false;
				}

				s.pop();
				prev = p;
				current = p->val;
				p = p->right;
			}
		}
				
		if (first && second) {
			swap(first->val, second->val);
		}
	}
};

//int main(int argc, char* argv[]) {
//	TreeNode* root = new TreeNode(3);
//	root->left = new TreeNode(1);
//	root->right = new TreeNode(4);
//	TreeNode* tmp = root;
//	tmp = tmp->right;
//	tmp->left = new TreeNode(2);
//
//	Solution().recoverTree(root);
//
//	return 0;
//}