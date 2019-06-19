#include <vector>
#include <algorithm>
#include <map>
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

	//TODO：hashmap解法 fixed by 2019-6-19 10:51:37
	//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34541/5ms-Java-Clean-Solution-with-Caching
	//but Time Limit Exceeded testcase貌似有新增，无法通过极端测试用例，猜测是map耗时太长
	TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {
		map<int, int> inMap;
		for (int i = 0; i < inorder.size(); i++) {
			inMap.insert({ inorder[i], i });
		}
		TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> inMap) {
		if (preStart > preEnd || inStart > inEnd) return NULL;
		TreeNode* root = new TreeNode(preorder[preStart]);
		int inRoot = inMap[root->val];
		int numsLeft = inRoot - inStart;
		root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
		root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

		return root;
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> preorder = { 3,9,20,15,7 };
//	vector<int> inorder = { 9,3,15,20,7 };
//	TreeNode* root = Solution().buildTree2(preorder, inorder);
//	return 0;
//}