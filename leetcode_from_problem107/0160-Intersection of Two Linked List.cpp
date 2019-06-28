#include <cstddef>

// definition for singly-linked list.
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

// Runtime: 52 ms, faster than 76.41% of C++ online submissions for Intersection of Two Linked Lists.
// Memory Usage : 16.9 MB, less than 22.13 % of C++ online submissions for Intersection of Two Linked Lists.
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		// ���α���
		ListNode* pA = headA;
		ListNode* pB = headB;
		// ��һ�α����ҵ���������Ĳ�ֵ��δ�������յ�Ľ�����յ�ľ��뼴�ǲ�ֵ���Ӷ�������ʼ�α�
		while (pA && pB) {
			pA = pA->next;
			pB = pB->next;
		}
		// �������յ����Ϊ������ȡ��һ������ֵ�����α������ĩβʱǡ�ö���

		// �ݴ�pA����ֹpA���޸ĺ��޷���pB��ֵ
		ListNode* tmp = pA;
		pA = pA == NULL ? pB : headA;
		pB = pB == NULL ? tmp : headB;

		// �ڶ��α���������������ֵ����������
		while (pA && pB) {
			pA = pA->next;
			pB = pB->next;
		}
		pA = pA == NULL ? headA : pA;
		pB = pB == NULL ? headB : pB;

		// �����α��������Ƿ�����ͬ�Ľ�㣬������û�н���㣬ǰ���α��������Զ�����ʼ�α꣬������û����ͬ��㣬��˵��û�н�����
		while (pA && pB) {
			if (pA == pB) return pA;
			pA = pA->next;
			pB = pB->next;
		}
		return NULL;
	}
};

//int main(int argc, char* argv[]) {
//	ListNode* l1 = new ListNode(0);
//	ListNode* l2 = new ListNode(9);
//	ListNode* l3 = new ListNode(1);
//	ListNode* l4 = new ListNode(2);
//	ListNode* l5 = new ListNode(4);
//	ListNode* l6 = new ListNode(3);
//
//	l1->next = l2; l2->next = l3; l3->next = l4; l4->next = l5; l6->next = l4;
//
//	ListNode* l = Solution().getIntersectionNode(l1, l6);
//}