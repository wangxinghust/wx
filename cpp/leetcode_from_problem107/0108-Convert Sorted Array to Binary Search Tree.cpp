#include <vector>
using namespace std;

//definition for a binary tree node
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
	//Runtime: 16 ms, faster than 94.08% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
	//Memory Usage : 20.9 MB, less than 94.14 % of C++ online submissions for Convert Sorted Array to Binary Search Tree.
private:
	TreeNode* helper(vector<int>& nums, int start, int end) {
		if (start > end) return NULL;
		int mid = start + (end - start + 1) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = helper(nums, start, mid - 1);
		root->right = helper(nums, mid + 1, end);
		return root;
	}
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> nums = { -10,-3,0,5,9 };
//	TreeNode* root = Solution().sortedArrayToBST(nums);
//	return 0;
//}