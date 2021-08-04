// definition for a singly-linked list.
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};

// Runtime: 24 ms, faster than 13.37% of C++ online submissions for Odd Even Linked List.
// Memory Usage : 9.7 MB, less than 32.08 % of C++ online submissions for Odd Even Linked List.
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr) return nullptr;
		if (head->next == nullptr) return head;
		ListNode* odd = head;
		ListNode* even_start = head->next;
		ListNode* even = even_start;
		while (odd->next && even->next) {
			// 隔一个连接
			odd->next = even->next;
			// 移动odd
			odd = odd->next;
			// 隔一个连接
			even->next = odd->next;
			// 移动even
			even = even->next;
		}
		odd->next = even_start;
		return head;
	}
};