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
			// ��һ������
			odd->next = even->next;
			// �ƶ�odd
			odd = odd->next;
			// ��һ������
			even->next = odd->next;
			// �ƶ�even
			even = even->next;
		}
		odd->next = even_start;
		return head;
	}
};