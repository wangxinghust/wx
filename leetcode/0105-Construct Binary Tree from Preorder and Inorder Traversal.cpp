#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//You may assume that duplicates do not exist in the tree.

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty()) return NULL;
		TreeNode* root = new TreeNode(preorder[0]);
		auto position = find(inorder.begin(), inorder.end(), preorder[0]);
		vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + (position - inorder.begin() + 1));
		vector<int> preorderRight(preorder.begin() + (position - inorder.begin() + 1), preorder.end());
		vector<int> inorderLeft(inorder.begin(), position);
		vector<int> inorderRight(position + 1, inorder.end());
		root->left = buildTree(preorderLeft, inorderLeft);
		root->right = buildTree(preorderRight, inorderRight);
		return root;
	}

	//TODO£ºhashmap½â·¨
	//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34541/5ms-Java-Clean-Solution-with-Caching
};

//int main(int argc, char* argv[]) {
//	vector<int> preorder = { 3,9,20,15,7 };
//	vector<int> inorder = { 9,3,15,20,7 };
//	TreeNode* root = Solution().buildTree(preorder, inorder);
//	return 0;
//}