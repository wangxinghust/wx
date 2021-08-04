#include <cstddef>
#include <stack>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Runtime: 4 ms, faster than 93.42% of C++ online submissions for Flatten Binary Tree to Linked List.
// Memory Usage : 9.7 MB, less than 87.50 % of C++ online submissions for Flatten Binary Tree to Linked List.
// 解题思路：考虑到把左孩子移至右边有冲突，因此先全部往左放，采用前序遍历，设置一个prev指针，保存最后一个左结点
// 最后一次循环，将所有左孩子往右移即可
class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == NULL) return;
		TreeNode* p = root, * prev = NULL;
		stack<TreeNode*> st;
		while (p || !st.empty()) {
			while (p) {
				// 存储最后的左孩子，即前序遍历的操作
				prev = p;

				st.push(p);
				p = p->left; // 牢记遍历的递增语句
			}
			if (!st.empty()) {
				p = st.top();
				st.pop();

				// 将右孩子移至prev的左子树，即中序遍历的操作
				prev->left = p->right;

				p = p->right; // 牢记遍历的递增语句
			}
		}

		// 最后循环，将左孩子全部移到右边
		p = root;
		while (p) {
			p->right = p->left;
			p->left = NULL;
			p = p->right;
		}
	}
};

// leetcode by jaewoo
// 对每个结点root，确定它的左孩子和右孩子，找左孩子的最后一个右孩子right，将root的右孩子链接到最后一个右孩子right上
// 然后删除root的右孩子，移动root的左孩子到右边，将root往下移
// 每个结点应该只会被遍历一次，因而是时间复杂度是O(n)，空间复杂度为O(1)
// Runtime: 4 ms, faster than 93.42% of C++ online submissions for Flatten Binary Tree to Linked List.
// Memory Usage : 9.5 MB, less than 100.00 % of C++ online submissions for Flatten Binary Tree to Linked List.
class Solution2 {
public:
	void flatten(TreeNode* root) {
		while (root) {
			if (root->left && root->right) {
				TreeNode* tmp = root->left;
				while (tmp->right) {
					tmp = tmp->right;
				}
				tmp->right = root->right;
			}

			if (root->left) {
				root->right = root->left;
			}

			// 别忘了移动后删除左孩子
			root->left = NULL;
			root = root->right;
		}
	}
};

//int main(int argc, char* argv[]) {
//	TreeNode p0(1), p1(2), p2(5), p3(3), p4(4), p5(6);
//	p0.left = &p1;
//	p0.right = &p2;
//	p1.left = &p3;
//	p1.right = &p4;
//	p2.right = &p5;
//	Solution().flatten(&p0);
//	return 0;
//}