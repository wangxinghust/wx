#include <cstddef>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//0082�ļ򻯰�
	//Runtime: 12 ms, faster than 91.05% of C++ online submissions for Remove Duplicates from Sorted List.
	//Memory Usage : 9.5 MB, less than 5.66% of C++ online submissions for Remove Duplicates from Sorted List.
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) return NULL;
		if (!head->next) return head;
		ListNode* second = head;
		ListNode* secondLast = NULL;
		ListNode* first = head;
		ListNode* firstLast = NULL;
		while (first) {
			//ɾ�����������жϼ���
			if (!firstLast || firstLast->val != first->val) {
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

	// Ҳ������д��ֻ�Ƚ�����ߵ�ֵ�Ƿ���ȣ������ɾȥ���߽��
	// leetcode Approach 1: Straight-Forward Approach
	//Runtime: 4 ms, faster than 99.97% of C++ online submissions for Remove Duplicates from Sorted List.
	//Memory Usage : 9.3 MB, less than 18.77% of C++ online submissions for Remove Duplicates from Sorted List.
	ListNode* deleteDuplicates2(ListNode* head) {
		ListNode* current = head;
		while (current&&current->next) {
			if (current->next->val == current->val) {
				current->next = current->next->next;
			}
			else {
				current = current->next;
			}
		}
		return head;
	}
};