#include <stack>
using namespace std;

// definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		stack<ListNode*> s;
		ListNode* ln = head;
		while (ln) {
			s.push(ln);
			ln = ln->next;
		}
		if (s.size() <= 2) return;
		int end = (s.size() - 1) / 2;
		ln = head;
		for (int i = 0; i < end; i++) {
			ListNode* next = ln->next;
			ln->next = s.top();
			s.pop();
			s.top()->next = nullptr;// 断开末尾的指针很重要
			ln->next->next = next;
			ln = next;
		}
	}
};

// leetcode by shichaotan
// 快慢指针找中,分割，反转，合并
class Solution2 {
public:
	void reorderList(ListNode* head) {
		if (!head || !head->next) return;
		// find the middle node: O(n)
		ListNode* p1 = head, * p2 = head->next;
		while (p2 && p2->next) {
			p1 = p1->next;
			p2 = p2->next->next;
		}

		// cut from the midlle and reverse the second half:O(n)
		ListNode* head2 = p1->next;
		p1->next = nullptr;

		p2 = head2->next;
		head2->next = nullptr;
		while (p2) {
			p1 = p2->next;

			p2->next = head2;

			head2 = p2;
			p2 = p1;
		}

		// merge two lists:O(n)
		for (p1 = head, p2 = head2; p1;) {
			ListNode* t = p1->next;
			p1 = p1->next = p2;
			p2 = t;
		}
	}
};

//int main() {
//	ListNode* p1 = new ListNode(1);
//	ListNode* p2 = new ListNode(2);
//	ListNode* p3 = new ListNode(3);
//	ListNode* p4 = new ListNode(4);
//	p1->next = p2;
//	p2->next = p3;
//	p3->next = p4;
//	Solution().reorderList(p1);
//	return 0;
//}