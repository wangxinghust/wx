#include <cstddef>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
		//���������α�ָ��
		ListNode* pList1 = l1;
		ListNode* pList2 = l2;
		//����ͷָ�룬�������ж�ͷָ��ָ����Ҫ�жϸ���nullptr���
		ListNode* pMergeHead = nullptr;
		if (pList1 == nullptr)
		{
			pMergeHead = pList2;
		}
		else if (pList2 == nullptr)
		{
			pMergeHead = pList1;
		}
		else
		{
			//��Ҫ���ǵ��ڵ���������¶�Ӧ�ĵط�ͬʱ����=��
			if (pList1->val <= pList2->val)
			{
				pMergeHead = pList1;
			}
			else
			{
				pMergeHead = pList2;
			}
		}
		//ѭ���ƶ����α�
		while (pList1 != nullptr && pList2 != nullptr)
		{
			//ͨ����ǰֵ�ıȽ��ж���Ҫ�ƶ��ĸ��α�
			if (pList1->val <= pList2->val)
			{
				//�ж��Ƿ�Խ�磬���Ƚ�ֵ
				while (pList1->next != nullptr && pList1->next->val <= pList2->val)
				{
					pList1 = pList1->next;
				}
				//Խ�磬1�����ֱ꣬�ӽ���2����return
				if (pList1->next == nullptr)
				{
					pList1->next = pList2;
					return pMergeHead;
				}
				//������ָ����һ��������Ҫע��tmp��ʱ������ʹ�ã����ڱ�������
				ListNode* tmp = pList1->next;
				pList1->next = pList2;
				pList1 = tmp;
			}
			//����ͬ�ϣ���else�������Ǽ����жϣ�дif��ʱ�������else�������elseΪ�գ�����©�ж���
			else
			{
				while (pList2->next != nullptr && pList2->next->val < pList1->val)
				{
					pList2 = pList2->next;
				}
				if (pList2->next == nullptr)
				{
					pList2->next = pList1;
					return pMergeHead;
				}
				ListNode* tmp = pList2->next;
				pList2->next = pList1;
				pList2 = tmp;
			}
		}
		return pMergeHead;
	}

	//leetcode 
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummy(INT_MIN);
		ListNode* tail = &dummy;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			}
			else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}
		tail->next = l1 ? l1 : l2;
		return dummy.next;
	}
};

//int main(int argc, char* argv[]) {
//	ListNode l1(1), l2(2), l3(4), l4(1), l5(3), l6(4);
//	l1.next = &l2;
//	l2.next = &l3;
//	l4.next = &l5;
//	l5.next = &l6;
//	ListNode* pMergeHead;
//	Solution s;
//	pMergeHead = s.mergeTwoLists(&l1, &l4);
//	while (pMergeHead) {
//		std::cout << pMergeHead->val << std::endl;
//		pMergeHead = pMergeHead->next;
//	}
//	return 0;
//}