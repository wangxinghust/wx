#include <vector>
using namespace std;
//definition for singly-linked list.
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x) {
		val = x;
		next = nullptr;
	}
	ListNode(int x, ListNode* n) {
		val = x;
		next = n;
	}
};
class ListBuilder {
public:
	int v;
	ListNode* p;
	ListBuilder(ListNode* p = nullptr) :v(0), p(p) {}
	ListBuilder(int d, ListBuilder b = ListBuilder())
		:v(d), p(new ListNode(d, b.p)) {}
	operator ListNode* () const {
		return p;
	}
};

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
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> nums;
		ListNode* p = head;
		while (p) {
			nums.push_back(p->val);
			p = p->next;
		}
		TreeNode* root = helper(nums, 0, nums.size() - 1);
		return root;
	}

	// leetcode Approach 1: Recursion
	// two pointer: slow_ptr&fast_ptr. The slow_ptr moves one node at a time whereas the fast_ptr moves two nodes at a time. 
	ListNode* findMiddleElement(ListNode* head) {
		// the pointer used to disconnect the left half from the mid node. 
		ListNode* prevPtr = NULL;
		ListNode* slowPtr = head;
		ListNode* fastPtr = head;

		// Iterate until fastPtr doesn't reach the end of the linked list. 
		while (fastPtr != NULL && fastPtr->next != NULL) {
			prevPtr = slowPtr;
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next->next;
		}
		// Handling the case when slowPtr was equal to head. 
		if (prevPtr != NULL) {
			prevPtr->next = NULL;
		}

		return slowPtr;
	}
	
	TreeNode* sortedListToBST2(ListNode* head) {
		// If the head doesn't exist, then the linked list is empty.
		if (head == NULL) return NULL;

		// Find the middle element for the list. 
		ListNode* mid = this->findMiddleElement(head);

		// the mid becomes the root of the BST.
		TreeNode* node = new TreeNode(mid->val);

		// base case when there is just one element in the linked list
		if (head == mid) return node;

		// recursively form balanced BSTs using the left and right halves of the original list.
 		return node;
	}
};

//int main(int argc, char* argv[]) {
//	ListNode* list = ListBuilder{ 1,{2,{3}} };
//	TreeNode* root = Solution().sortedListToBST(list);
//	return 0;
//}