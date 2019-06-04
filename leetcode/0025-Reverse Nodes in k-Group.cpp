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
			//�ȶ�����
			auto tmp = first->next;//����firstָ��ĺ�һ��
			first->next = prev;//��ָ��first->next
			prev = first;//�ƶ�prev
			first = tmp;//�ָ�����
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
		//headָ��û�б仯�����ǿ�ͷ��ֻ��ָ�����˱仯
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