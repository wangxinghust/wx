#include <vector>
using namespace std;

//definition for a binary tree node.
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
	//recursion
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}
	TreeNode* helper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int poStart, int poEnd) {
		if (inStart >= inEnd || poStart >= poEnd) return NULL;
		int mid = postorder[poEnd - 1];
		auto p = find(inorder.begin() + inStart, inorder.begin() + inEnd, mid);
		int dis = p - inorder.begin() - inStart;

		TreeNode* root = new TreeNode(mid);
		root->left = helper(inorder, inStart, inStart + dis, postorder, poStart, poStart + dis);
		root->right = helper(inorder, inStart + dis + 1, inEnd, postorder, poStart + dis, poEnd - 1);
		return root;
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> inorder = { 9,3,15,20,7 };
//	vector<int> postorder = { 9,15,7,20,3 };
//	TreeNode* root = Solution().buildTree(inorder, postorder);
//	return 0;
//}