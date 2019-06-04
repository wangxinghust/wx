#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//by wx Runtime: 284 ms, faster than 16.08% of C++ online submissions for Merge k Sorted Lists.
	//Memory Usage : 10.7 MB, less than 95.85% of C++ online submissions for Merge k Sorted Lists.
	ListNode* mergeKLists1(vector<ListNode*>& lists) {
		if (lists.size()) {
			vector<ListNode*>::iterator it = lists.begin();
			while (it != lists.end()) {
				if (*it == nullptr) {
					//删除指定元素，返回指向删除元素的下一个元素的位置的迭代器
					it = lists.erase(it);
				}
				else {
					++it;
				}
			}
		}
		ListNode dummy(INT_MIN);
		ListNode* tail = &dummy;
		while (lists.size()) {
			int minIndex = getMinIndex(lists);
			tail->next = lists[minIndex];
			lists[minIndex] = lists[minIndex]->next;
			if (!lists[minIndex]) {
				lists.erase(lists.begin() + minIndex);
			}
			tail = tail->next;
		}
		return dummy.next;
	}
	int getMinIndex(vector<ListNode*> & listsCur) {
		int minIndex = 0;
		for (int i = 1; i < (int)listsCur.size(); ++i) {
			if (listsCur[i] == nullptr) {
				continue;
			}
			if (listsCur[i]->val < listsCur[minIndex]->val) {
				minIndex = i;
			}
		}
		return minIndex;
	}

	//leetcode Approach1:Brute Force
	//Runtime: 24 ms, faster than 99.09% of C++ online submissions for Merge k Sorted Lists.
	//Memory Usage : 11.9 MB, less than 35.46% of C++ online submissions for Merge k Sorted Lists.
	ListNode* mergeKLists2(vector<ListNode*> & lists) {
		vector<int> valAll;
		for (ListNode* l : lists) {
			while (l) {
				valAll.push_back(l->val);
				l = l->next;
			}
		}
		if (!valAll.size()) {
			return nullptr;
		}
		sort(valAll.begin(), valAll.end());
		ListNode dummy(0);
		ListNode* tail = &dummy;
		for (int i = 0; i < (int)valAll.size(); ++i) {
			ListNode* tmp = new ListNode(valAll[i]);
			tail->next = tmp;
			tail = tmp;
		}
		return dummy.next;
	}

	//LeetCode Approach2: Compare one by one

	//LeetCode Approach3: Optimize Approach by Priority Queue
	//Runtime: 32 ms, faster than 67.63% of C++ online submissions for Merge k Sorted Lists.
	//Memory Usage : 11.3 MB, less than 69.55% of C++ online submissions for Merge k Sorted Lists.
	ListNode* mergeKLists3(vector<ListNode*> & lists) {
		priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*> >, greater<pair<int, ListNode*> > > p;
		int i;
		ListNode dummy(0);
		ListNode* tail = &dummy;
		for (ListNode* l : lists) {
			if (l) {
				p.push(make_pair(l->val, l));
			}
		}
		if (p.empty()) return dummy.next;
		while (!p.empty()) {
			pair<int, ListNode*> tmp = p.top();
			p.pop();
			if (tmp.second->next) p.push({ tmp.second->next->val,tmp.second->next });
			tail->next = tmp.second;
			tail = tail->next;
		}
		return dummy.next;
	}

	//LeetCode Approach 4: Merge lists one by one
	//Convert merge \text{k}k lists problem to merge 2 lists (k-1) times

	//LeetCode Approach 5:Merge with Divide And Conquer
	//Runtime: 24 ms, faster than 99.09% of C++ online submissions for Merge k Sorted Lists.
	//Memory Usage : 11 MB, less than 86.63% of C++ online submissions for Merge k Sorted Lists.
	ListNode* mergeKLists(vector<ListNode*> & lists) {
		int length = lists.size();
		if (length <= 0) return nullptr;
		int interval = 1;
		while (interval < length) {
			for (int i = 0; i < length - interval; i += interval * 2) {
				lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
			}
			interval *= 2;
		}
		return lists[0];
	}
	ListNode* mergeTwoLists(ListNode * l1, ListNode * l2) {
		ListNode dummy(INT_MIN);
		ListNode* tail = &dummy;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			}
			else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}
		tail->next = l1 ? l1 : l2;
		return dummy.next;
	}
};


//int main(int argc, char* argv[]) {
//	ListNode l1(1), l2(4), l3(5), l4(1), l5(3), l6(4), l7(2), l8(6);
//	l1.next = &l2; l2.next = &l3; l4.next = &l5; l5.next = &l6; l7.next = &l8;
//	Solution s;
//	vector<ListNode*> lists = { &l1,&l4,&l7 };
//	ListNode* pHead = s.mergeKLists(lists);
//	return 0;
//}