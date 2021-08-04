#include <cstddef>

//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//由0026双指针解法改进
	//Runtime: 4 ms, faster than 99.79% of C++ online submissions for Remove Duplicates from Sorted List II.
	//Memory Usage : 9.2 MB, less than 39.79% of C++ online submissions for Remove Duplicates from Sorted List II.
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) return NULL;
		if (!head->next) return head;
		ListNode* second = head;
		ListNode* secondLast = NULL;
		ListNode* first = head;
		ListNode* firstLast = NULL;
		while (first) {
			if ((!firstLast || firstLast->val != first->val) && (!first->next || first->next->val != first->val)) {
				second->val = first->val;
				secondLast = second;
				second = second->next;
			}
			firstLast = first;
			first = first->next;
		}
		if (secondLast) {
			secondLast->next = NULL;
			return head;
		}
		else return NULL;
	}
};

//int main(int argc, char* argv[]) {
//	ListNode a1(1), a2(2), a3(2);
//	a1.next = &a2; a2.next = &a3;
//	Solution s;
//	ListNode* newHead = s.deleteDuplicates(&a1);
//	return 0;
//}