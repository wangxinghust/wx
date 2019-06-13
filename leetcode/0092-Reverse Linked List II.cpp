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
		//���ڷ���newHead->next�����㴦���ͷ��ʼreverse�ȸ������
		ListNode* newHead = new ListNode(0);
		newHead->next = head;

		//��������m-1�����
		ListNode* p = newHead;
		int i = 1;
		while (i < m && p) {
			p = p->next;
			i++;
		}
		//���õ�m-1�����Ϊstart����m�����Ϊend
		ListNode* start = p;
		ListNode* end = p->next;

		//��ʼ��last��next
		ListNode* last = start;
		ListNode* next = end;
		while (i <= n && p) {
			//���ݵ�ǰ���Ϊlast�������´�ѭ��ʹ��
			last = p;
			//��p�ƶ���next
			p = next;
			//���ݵ�ǰp->next�������´�ѭ��ʹ��
			next = p->next;
			//�ı�p->nextʹ��
			p->next = last;
			//i����
			i++;
		}

		//��ת���ֵ�endָ��ʣ�µ�����
		end->next = next;
		//��ת���ֵ�ǰһ�����(start)�����ϵ�ǰ���(����ת���������ͷ��)
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