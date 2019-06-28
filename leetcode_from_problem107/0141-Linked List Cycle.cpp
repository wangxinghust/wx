// definition for singly-linke list.
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x) {
		val = x;
		next = nullptr;
	}
};

// ¿ìÂıÖ¸Õë
// Runtime: 8 ms, faster than 98.69% of C++ online submissions for Linked List Cycle.
// Memory Usage : 9.7 MB, less than 65.64 % of C++ online submissions for Linked List Cycle.
class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (!head || !head->next) return false;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow) {
				return true;
			}
		}
		return false;
	}
};