#include <cstddef>
#include <climits>

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	//赋默认值 ListNode* n = NULL 时，构造函数不明确
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
			//备份current->next节点，避免修改后无法更新current
			ListNode* tmp = current->next;
			//遍历到小于x的ListNode,且前一ListNode的值大于等于x，需要移动该ListNode
			if (current->val < x && (last && last->val >= x)) {
				//last指向current->next，也即取出current
				last->next = current->next;
				//current连上first指针后的东西
				current->next = first->next;
				//first指针连上current
				first->next = current;
				//移动first指向下一位置
				first = first->next;
			}
			//遍历到小于x的ListNode，但前一ListNode的值小于x，只需移动first和last指针
			else if (current->val < x) {
				first = first->next;
				last = last->next;
			}
			//遍历到大于等于x的ListNode，只需要移动last指针
			else {
				last = last->next;
			}
			//更新current指针
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