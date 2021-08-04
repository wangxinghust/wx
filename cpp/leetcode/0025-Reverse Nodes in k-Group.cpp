#include <cstddef>
#include <vector>
//  Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup1(ListNode* head, int k) {
		if (!head) return nullptr;
		std::vector<ListNode*> list(k);
		int i = 0;
		while (head && i < k) {
			list[i] = head;
			++i;
			head = head->next;
		}
		if (i < k) return list[0];
		for (int i = 0; i+1 < k; ++i) {
			list[i+1]->next = list[i];
		}
		list[0]->next = reverseKGroup(head, k);
		return list[k - 1];
	}

	//leetcode
	ListNode* reverse(ListNode* first, ListNode* last)
	{
		ListNode* prev = last;

		while (first != last)
		{
			//先断再连
			auto tmp = first->next;//备份first指针的后一个
			first->next = prev;//重指向first->next
			prev = first;//移动prev
			first = tmp;//恢复备份
		}
		return prev;
	}

	ListNode* reverseKGroup(ListNode* head, int k)
	{
		auto node = head;
		for (int i = 0; i < k; ++i)
		{
			if (!node)
				return head; // nothing to do list too sort
			node = node->next;
		}
		auto new_head = reverse(head, node);
		//head指针没有变化，还是开头，只是指向发生了变化
		head->next = reverseKGroup(node, k);
		return new_head;
	}
};

//int main(int argc, char* argv[]) {
//	ListNode dummy(0);
//	ListNode* tail = &dummy;
//	for (int i = 1; i <= 5; ++i) {
//		ListNode* tmp = new ListNode(i);
//		tail->next = tmp;
//		tail = tmp;
//	}
//	Solution s;
//	ListNode* pHead = s.reverseKGroup(dummy.next, 3);
//	return 0;
//}