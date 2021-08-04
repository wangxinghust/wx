// definition for a singly-linked list.
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

// Runtime: 20 ms, faster than 12.04% of C++ online submissions for Delete Node in a Linked List.
// Memory Usage : 9.1 MB, less than 78.99 % of C++ online submissions for Delete Node in a Linked List.
class Solution {
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
};