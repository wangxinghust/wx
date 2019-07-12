// definition for singly-linked list.
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

// leetcode by alex_tsitsura
// ���õݹ��ջ�����ռ临�Ӷ�Ӧ����O(n)
// Runtime: 20 ms, faster than 94.05% of C++ online submissions for Palindrome Linked List.
// Memory Usage : 14.4 MB, less than 9.75 % of C++ online submissions for Palindrome Linked List.
class Solution {
public:
	ListNode* temp;
	bool isPalindrome(ListNode* head) {
		temp = head;
		return check(head);
	}
private:
	bool check(ListNode* p) {
		if (nullptr == p) return true;
		bool isPal = check(p->next) & (temp->val == p->val);
		temp = temp->next;
		return isPal;
	}
};

// leetcode by YCG09
// ����ָ���������е�
// ��ת��벿������
// ���м������߱Ƚ�
// Runtime: 24 ms, faster than 77.58% of C++ online submissions for Palindrome Linked List.
// Memory Usage : 12.8 MB, less than 51.77 % of C++ online submissions for Palindrome Linked List.
class Solution2 {
public:
	bool isPalindrome(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return true;
		// �������е�
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast->next != nullptr && fast->next->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		// ��ת��벿������
		slow->next = reverseList(slow->next);
		slow = slow->next;
		// ���αȽ�
		while (slow != nullptr) {
			if (head->val != slow->val) return false;
			head = head->next;
			slow = slow->next;
		}
		return true;
	}
private:
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode* next = nullptr;
		while (head != nullptr) {
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
};

//int main(int argc, char* argv[]) {
//	ListNode* l1 = new ListNode(1);
//	ListNode* l2 = new ListNode(2);
//	ListNode* l3 = new ListNode(2);
//	ListNode* l4 = new ListNode(1);
//	l1->next = l2; l2->next = l3; l3->next = l4;
//	bool b = Solution().isPalindrome(l1);
//	return 0;
//}