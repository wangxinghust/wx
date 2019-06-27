
// definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;
	Node() {}
	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};

// leetcode by satyakam
class Solution {
public:

	// Runtime: 32 ms, faster than 88.35 % of C++ online submissions for Copy List with Random Pointer.
	// Memory Usage : 22 MB, less than 78.34 % of C++ online submissions for Copy List with Random Pointer.
	Node* copyRandomList(Node* head) {
		if (!head) return nullptr;
		Node* newHead, * l1, * l2;
		// ��l2���������l1���ĺ���
		for (l1 = head; l1 != nullptr; l1 = l1->next->next) {
			// ����l2���
			l2 = new Node(l1->val, nullptr, nullptr);
			// ����l2���
			l2->next = l1->next;
			l1->next = l2;
		}

		// ����ͷ���
		newHead = head->next;

		// ����randomָ��
		for (l1 = head; l1 != nullptr; l1 = l1->next->next) {
			if (l1->random != nullptr) l1->next->random = l1->random->next;
		}

		// ɾ����������l1���Ľ��
		for (l1 = head; l1 != nullptr; l1 = l1->next) {
			l2 = l1->next;
			l1->next = l2->next;
			if (l2->next != nullptr) l2->next = l2->next->next;
		}

		return newHead;
	}

	// ����randomָ�����ݴ渴�Ƶ�l2���
	// Runtime: 28 ms, faster than 97.17% of C++ online submissions for Copy List with Random Pointer.
	// Memory Usage : 21.8 MB, less than 94.51 % of C++ online submissions for Copy List with Random Pointer.
	Node* copyRandomList2(Node* head) {
		if (!head) return nullptr;
		Node* newHead, * l1, * l2;

		for (l1 = head; l1; l1 = l1->next) {
			l2 = new Node(l1->val, nullptr, nullptr);
			l2->next = l1->random;
			l1->random = l2;
		}

		newHead = head->random;

		for (l1 = head; l1; l1 = l1->next) {
			l2 = l1->random;
			l2->random = l2->next ? l2->next->random : nullptr;
		}

		for (l1 = head; l1; l1 = l1->next) {
			l2 = l1->random;
			l1->random = l2->next;
			l2->next = l1->next ? l1->next->random : nullptr;
		}
		return newHead;
	}
};

//int main(int argc, char* argv[]) {
//	Node* n1, * n2;
//	n1 = new Node(1, nullptr, nullptr);
//	n2 = new Node(2, nullptr, nullptr);
//	n1->next = n2;
//	n1->random = n2;
//	n2->random = n2;
//
//	Node* ans = Solution().copyRandomList(n1);
//	return 0;
//}