// difinition for singly-linke list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;

		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* cur = head->next;
		ListNode* pre = head;
		while (cur) {
			ListNode* next = cur->next;
			ListNode* comp = dummyHead;
			while (comp->next->val < cur->val) {
				comp = comp->next;
			}
			if (comp == pre) {
				pre = cur;
				cur = next;				
				continue;
			}
			ListNode* compNext = comp->next;

			pre->next = next;

			comp->next = cur;
			cur->next = compNext;

			cur = next;
		}
		return dummyHead->next;
	}
};