#include <cstddef>

//  Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head) return nullptr;
		if (!head->next) return head;
		ListNode* l = head;
		head = head->next;
		ListNode* tmp = head->next;
		head->next = l;
		l->next = swapPairs(tmp);
		return head;
	}
};

//int main(int argc, char argv[]) {
//	ListNode dummy(0);
//	ListNode* tail = &dummy;
//	for (int i = 1; i <= 4; ++i) {
//		ListNode* tmp = new ListNode(i);
//		tail->next = tmp;
//		tail = tmp;
//	}
//	Solution s;
//	ListNode* pHead = s.swapPairs(dummy.next);
//	return 0;
//}