#include <cstddef>
#include <algorithm>
#include <tuple>
using namespace std;
// definition for singly-linked list.
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

// 基于快排 双指针 保证比枢纽值小的都在慢指针左侧，比枢纽值大的在慢指针和快指针之间，快指针到位后，将慢指针的值和枢纽值交换即可
// Runtime: 456 ms, faster than 11.04% of C++ online submissions for Sort List.
// Memory Usage : 14.8 MB, less than 35.70 % of C++ online submissions for Sort List.
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		qsortList(head, NULL);
		return head;
	}
	void qsortList(ListNode* head, ListNode* tail) {
		// 链表范围是[low,high) 是为了找到mid后不用向前找mid-1，而是取mid->next
		if (head != tail && head->next != tail) {
			ListNode* mid = partitionList(head, tail);
			qsortList(head, mid);
			qsortList(mid->next, tail);
		}
	}
	ListNode* partitionList(ListNode* low, ListNode* high) {
		// 链表范围是[low,high)
		int key = low->val;
		ListNode* loc = low;
		for (ListNode* i = low->next; i != high; i = i->next) {
			if (i->val < key) {
				loc = loc->next;
				swap(i->val, loc->val);
			}
		}
		swap(loc->val, low->val);
		return loc;
	}
};


// 归并排序，在数组排序中空间复杂度为O(n)，在链表排序中降至O(1)
// Runtime: 456 ms, faster than 11.04% of C++ online submissions for Sort List.
// Memory Usage : 14.8 MB, less than 35.70 % of C++ online submissions for Sort List.
class Solution2 {
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		// 让快慢指针找到中间节点
		ListNode* fast = head, * slow = head;
		while (fast->next != NULL && fast->next->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow;
		slow = slow->next;
		fast->next = NULL;
		fast = sortList(head); // 前半段排序
		slow = sortList(slow); // 后半段排序
		return merge(fast, slow);
	}

	// merge two sorted list to one
	ListNode* merge(ListNode* head1, ListNode* head2) {
		if (head1 == NULL) return head2;
		if (head2 == NULL) return head1;
		ListNode* res, * p;
		// 合并两条排好序的链表
		if (head1->val < head2->val) {
			res = head1;
			head1 = head1->next;
		}
		else {
			res = head2;
			head2 = head2->next;
		}
		p = res;
		while (head1 != NULL && head2 != NULL) {
			if (head1->val < head2->val) {
				p->next = head1;
				head1 = head1->next;
			}
			else {
				p->next = head1;
				head2 = head2->next;
			}
			p = p->next;
		}
		return res;
	}
};

// leetcode by ChrisTrompf 同样基于归并排序
// Runtime: 44 ms, faster than 91.51% of C++ online submissions for Sort List.
// Memory Usage : 11.6 MB, less than 90.30 % of C++ online submissions for Sort List.
class Solution3 {
	ListNode* sortList(ListNode* head) {
		bool done = (!head);
		// Keep partitioning our list into bigger sublists length. Starting with a size of 1 and doubling each time
		for (int step = 1; !done; step *= 2) {
			done = true;
			ListNode** next_ptr = &head;
			ListNode* remaining = head;
			ListNode* list[2];
			do {
				// Split off two sublists of size step
				for (auto& sub_head : list) {
					sub_head = remaining;
					ListNode* tail = nullptr;
					for (int i = 0; i < step && remaining; ++i, remaining = remaining->next) {
						tail = remaining;
					}
					// Terminate our sublist
					if (tail) {
						tail->next = nullptr;
					}
				}

				// We're done if these are the first two sublists in this pass and they
				// encompass the entire primary list
				done &= !remaining;

				// If we have two sublists, merge them into one
				if (list[1]) {
					while (list[0] || list[1]) {
						int idx = (!list[1] || list[0] && list[0]->val <= list[1]->val) ? 0 : 1;
						*next_ptr = list[idx];
						list[idx] = list[idx]->next;
						next_ptr = &(**next_ptr).next;
					}

					// Terminate our new sublist
					*next_ptr = nullptr;
				}
				else {
					// Only a single sublist, no need to merge, just attach to the end
					*next_ptr = list[0];
				}
			} while (remaining);
		}
		return head;
	}
};

// Using a holding buffer for extra speed. O(nlogn) time, O(1) space, with lower constant. 未能通过测试用例： [1]
class Solution4 {
	/// Merge two sorted lists into one, the head and tail of the new list is returned
	std::pair<ListNode*, ListNode*> merge_lists(ListNode* l1, ListNode* l2)
	{
		ListNode* head;
		ListNode* tail = nullptr;
		ListNode** next_ptr = &head;
		while (l1 || l2) {
			ListNode** list = (!l2 || l1 && l1->val <= l2->val) ? &l1 : &l2;
			*next_ptr = tail = *list;
			*list = (*list)->next;
			next_ptr = &(*next_ptr)->next;
		}
		*next_ptr = nullptr;
		return std::make_pair(head, tail);
	}

	/// Take a list and split it into sublists of the requested size, returns number sublists and remaining list
	std::pair<int, ListNode*> split_list(ListNode* head, int sz, ListNode* lists[], int num_lists)
	{
		int count = 0;
		while (head && count < num_lists) {
			lists[count++] = head;
			ListNode* list_tail = nullptr;
			for (int i = 0; i < sz && head; ++i, head = head->next) {
				list_tail = head;
			}
			if (list_tail) {
				list_tail->next = nullptr;
			}
		}
		return std::make_pair(count, head);
	}

	ListNode* sortList(ListNode* head)
	{
		// Working buffer size, must be an even number
		constexpr int buf_sz = 8;
		ListNode* buf[buf_sz];

		bool done = (!head);
		// Initially split list into sublists of size 1, then increase the size until
		// the entire list is sorted
		for (int step = 1; !done; step *= buf_sz) {
			done = true;
			int num;
			ListNode* remaining = head;
			ListNode* tail = nullptr;
			ListNode** next_ptr = &head;
			do {
				// Split the list into increasingly larger sublists
				std::tie(num, remaining) = split_list(remaining, step, buf, buf_sz);

				// We'll be done if this is the first split this pass and there is no more remaining
				done &= (!remaining);

				// Keep merging our sublists together until a single sorted list is made
				for (; 1 < num; num = (num + 1) / 2) {
					// Merge each pair of sublists
					for (int i = 0; i < num / 2; ++i) {
						std::tie(buf[i], tail) = merge_lists(buf[i * 2], buf[i * 2 + 1]);
					}

					// If there is an odd number of lists, just move the last one. It will get
					// merged next time around
					if (num % 2) {
						buf[num / 2] = buf[num - 1];
					}
				}
				*next_ptr = buf[0];
				next_ptr = &(tail->next); // wrong: member access within null pointer of type 'struct ListNode'
			} while (remaining);
		}

		return head;
	}
};