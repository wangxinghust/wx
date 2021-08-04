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
		// 三次遍历
		ListNode* pA = headA;
		ListNode* pB = headB;
		// 第一次遍历找到两条链表的差值，未遍历到终点的结点离终点的距离即是差值，从而对齐起始游标
		while (pA && pB) {
			pA = pA->next;
			pB = pB->next;
		}
		// 遍历到终点的链为短链，取另一条链的值，该游标遍历到末尾时恰好对齐

		// 暂存pA，防止pA被修改后无法给pB赋值
		ListNode* tmp = pA;
		pA = pA == NULL ? pB : headA;
		pB = pB == NULL ? tmp : headB;

		// 第二次遍历，走完两链差值，对齐两链
		while (pA && pB) {
			pA = pA->next;
			pB = pB->next;
		}
		pA = pA == NULL ? headA : pA;
		pB = pB == NULL ? headB : pB;

		// 第三次遍历，找是否有相同的结点，无论有没有交叉点，前两次遍历都可以对齐起始游标，遍历完没有相同结点，则说明没有交叉结点
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