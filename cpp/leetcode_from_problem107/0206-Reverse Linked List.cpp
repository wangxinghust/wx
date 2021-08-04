// definition for a singly-linked list.
#include <cstddef>
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

// recursively
// Runtime: 8 ms, faster than 86.45% of C++ online submissions for Reverse Linked List.
// Memory Usage : 9.5 MB, less than 5.06 % of C++ online submissions for Reverse Linked List.
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) return head;
		ListNode* next = head->next;
		ListNode* newHead = reverseList(next);
		head->next = NULL;
		next->next = head;
		return newHead;
	}
};

// iteratively
// Runtime: 8 ms, faster than 86.45% of C++ online submissions for Reverse Linked List.
// Memory Usage : 9 MB, less than 85.31 % of C++ online submissions for Reverse Linked List.
class Solution2 {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) return NULL;// 可以省略，返回的是l
		ListNode* p = head;
		ListNode* l = NULL;
		while (p) {
			ListNode* n = p->next;
			p->next = l;
			l = p;
			p = n;
		}
		return l;
	}
};