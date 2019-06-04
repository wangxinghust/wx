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
		//建立两个游标指针
		ListNode* pList1 = l1;
		ListNode* pList2 = l2;
		//建立头指针，并初步判断头指针指向，需要判断各种nullptr情况
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
			//需要考虑等于的情况，以下对应的地方同时加上=号
			if (pList1->val <= pList2->val)
			{
				pMergeHead = pList1;
			}
			else
			{
				pMergeHead = pList2;
			}
		}
		//循环移动两游标
		while (pList1 != nullptr && pList2 != nullptr)
		{
			//通过当前值的比较判断需要移动哪个游标
			if (pList1->val <= pList2->val)
			{
				//判断是否越界，并比较值
				while (pList1->next != nullptr && pList1->next->val <= pList2->val)
				{
					pList1 = pList1->next;
				}
				//越界，1链走完，直接接上2链，return
				if (pList1->next == nullptr)
				{
					pList1->next = pList2;
					return pMergeHead;
				}
				//拆链，指向另一条链，需要注意tmp临时变量的使用，用于变量交换
				ListNode* tmp = pList1->next;
				pList1->next = pList2;
				pList1 = tmp;
			}
			//操作同上，用else，而不是继续判断，写if的时候多想想else在哪里，是else为空，还是漏判断了
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