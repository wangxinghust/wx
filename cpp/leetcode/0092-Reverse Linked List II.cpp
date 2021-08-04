#include <cstddef>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}

	//add
	ListNode(int v, ListNode* n) :val(v), next(n) {}
};

class Solution {
public:
	//Runtime: 4 ms, faster than 88.11% of C++ online submissions for Reverse Linked List II.
	//Memory Usage : 8.7 MB, less than 42.66 % of C++ online submissions for Reverse Linked List II.
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		//用于返回newHead->next，方便处理从头开始reverse等各种情况
		ListNode* newHead = new ListNode(0);
		newHead->next = head;

		//遍历到第m-1个结点
		ListNode* p = newHead;
		int i = 1;
		while (i < m && p) {
			p = p->next;
			i++;
		}
		//设置第m-1个结点为start，第m个结点为end
		ListNode* start = p;
		ListNode* end = p->next;

		//初始化last和next
		ListNode* last = start;
		ListNode* next = end;
		while (i <= n && p) {
			//备份当前结点为last，用于下次循环使用
			last = p;
			//将p移动至next
			p = next;
			//备份当前p->next，用于下次循环使用
			next = p->next;
			//改变p->next使用
			p->next = last;
			//i步进
			i++;
		}

		//反转部分的end指向剩下的链表
		end->next = next;
		//反转部分的前一个结点(start)，接上当前结点(即反转部分链表的头部)
		start->next = p;

		return newHead->next;
	}
};

struct ListBuilder {
	int v;
	ListNode* p;
	ListBuilder(ListNode* p = nullptr) :p(p) {}
	ListBuilder(int d, ListBuilder b = ListBuilder())
		:p(new ListNode(d, b.p)) {}
	operator ListNode* () const {
		return p;
	}
};
//int main(int argc, char* argv[]) {
//	ListNode* list = ListBuilder(1, { 2,{3,{4,{5}}} });
//	ListNode* ans = Solution().reverseBetween(list, 2, 4);
//	return 0;
//}