// definition for a singly-linked list.
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

// 哈希表

// floyd算法
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (head == nullptr) return nullptr;

		// if there is a cycle, the fast/slow pointers will intersect at some
		// node. Otherwise, there is no cycle, so we cannot find an entrance to a cycle.
		ListNode* intersect = getIntersect(head);
		if (intersect == nullptr) return nullptr;

		// to find the entrance to the cycle, we have two pointers traverse at
		// the same speed -- one from the front of the list, and the other from
		// the point of intersection
		ListNode* ptr1 = head;
		ListNode* ptr2 = intersect;
		while (ptr1 != ptr2) {
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		return ptr1;
	}
private:
	ListNode* getIntersect(ListNode* head) {
		ListNode* tortoise = head;
		ListNode* hare = head;

		// a fast pointer will either loop around a cycle and meet the slow
		// pointer or reach the 'null' at the end of a non-cyclic lis.
		while (hare != nullptr && hare->next != nullptr) {
			tortoise = tortoise->next;
			hare = hare->next->next;
			if (tortoise == hare) return tortoise;
		}

		return nullptr;
	}
};