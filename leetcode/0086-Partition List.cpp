#include <cstddef>
#include <climits>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	//��Ĭ��ֵ ListNode* n = NULL ʱ�����캯������ȷ
	ListNode(int v, ListNode* n) :val(v), next(n) {}
};

class Solution {
public:
	//Runtime: 8 ms, faster than 86.55% of C++ online submissions for Partition List.
	//Memory Usage : 8.7 MB, less than 52.40 % of C++ online submissions for Partition List.
	ListNode* partition(ListNode* head, int x) {
		ListNode* newHead = new ListNode(INT_MIN);
		newHead->next = head;
		ListNode* first = newHead;
		ListNode* current = head;
		ListNode* last = newHead;
		while (current) {
			//����current->next�ڵ㣬�����޸ĺ��޷�����current
			ListNode* tmp = current->next;
			//������С��x��ListNode,��ǰһListNode��ֵ���ڵ���x����Ҫ�ƶ���ListNode
			if (current->val < x && (last && last->val >= x)) {
				//lastָ��current->next��Ҳ��ȡ��current
				last->next = current->next;
				//current����firstָ���Ķ���
				current->next = first->next;
				//firstָ������current
				first->next = current;
				//�ƶ�firstָ����һλ��
				first = first->next;
			}
			//������С��x��ListNode����ǰһListNode��ֵС��x��ֻ���ƶ�first��lastָ��
			else if (current->val < x) {
				first = first->next;
				last = last->next;
			}
			//���������ڵ���x��ListNode��ֻ��Ҫ�ƶ�lastָ��
			else {
				last = last->next;
			}
			//����currentָ��
			current = tmp;
		}
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
//	Solution s;
//
//	ListNode* list = ListBuilder{ 1,{4,{3,{2,{5,{2}}}}} };
//	ListNode* ans = s.partition(list, 3);
//
//	/*ListNode* list = ListBuilder{ 2,{1} };
//	ListNode* ans = s.partition(list, 2);*/
//
//	return 0;
//}