#include <cstddef>

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//˼·��������������k+1����
	//Runtime: 8 ms, faster than 94.78% of C++ online submissions for Rotate List.
	//Memory Usage : 8.9 MB, less than 71.34 % of C++ online submissions for Rotate List.
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL) return head;
		ListNode* pFirst = head, * pSecond = head;
		for (int i = 0; i < k; ++i) {
			pFirst = pFirst->next;
			//�������������ĩβ��
			if (pFirst == NULL) { 
				pFirst = head;
				//���k������������Ż������ⷴ�����������Time Limit Exceeded
				k %= (i + 1);
				//ѭ����k%(i+1)����
				for (int j = 0; j < k; ++j) {
					pFirst = pFirst->next;
				}
				//�������ѭ��
				break;
			}
		}

		//����ص���ͷ��㣬Ҳ���������ص��˳�ʼ״̬
		if (pFirst == head) return head;

		while (pFirst->next != NULL) {
			pFirst = pFirst->next;
			pSecond = pSecond->next;
		}

		//�ݴ��µ�ͷ���
		ListNode* newHead = pSecond->next;

		//�Ͽ�����
		pSecond->next = NULL;

		//��������
		pFirst->next = head;

		return newHead;
	}
};