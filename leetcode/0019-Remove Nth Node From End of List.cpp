#include <cstddef>
#include <iostream>
//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* pFirst = head;
		ListNode* pSecond = head;
		for (int i = 0; i < n; ++i) {
			pFirst = pFirst->next;
		}
		if (pFirst == NULL) {
			//���head�Ƿ�Ϊ�㣬Ȼ����ȡ�����ã��Ա���NULLȡ�����ã����C28182���淽��
			if (head != 0) {
				return head->next;
			}
			else {
				return NULL;
			}
		}
		while (pFirst->next != NULL) {
			pFirst = pFirst->next;
			pSecond = pSecond->next;
		}
		if (pSecond->next != 0) {
			pSecond->next = pSecond->next->next;
		}		
		return head;
	}
};

void createList(ListNode* pHead) {
	ListNode* p = pHead;
	for (int i = 2; i < 3; ++i) {
		ListNode* pNewNode = new ListNode(i);
		p->next = pNewNode;
		p = pNewNode;
	}
}

//int main(int argc, char* argv[]) {
//	ListNode* pHead = NULL;
//	pHead = new ListNode(1);
//	createList(pHead);
//	ListNode* p = pHead;
//	/*while (p) {
//		std::cout << p->val << std::endl;
//		p = p->next;
//	}*/
//	Solution s;
//	p = pHead;
//	p = s.removeNthFromEnd(p, 2);
//	while (p) {
//		std::cout << p->val << std::endl;
//		p = p->next;
//	}
//	return 0;
//}