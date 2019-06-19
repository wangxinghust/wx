//definition for singly-linked list.
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int x) {
		val = x;
		next = nullptr;
	}
	ListNode(int x, ListNode* n) {
		val = x;
		next = n;
	}
};
class ListBuilder {
public:
	int v;
	ListNode* p;
	ListBuilder(ListNode* p = nullptr) :v(0), p(p) {}
	ListBuilder(int d, ListBuilder b = ListBuilder())
		:v(d), p(new ListNode(d, b.p)) {}
	operator ListNode* () const {
		return p;
	}
};

//definition for a binary tree node.
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) {
		val = x;
		left = nullptr;
		right = nullptr;
	}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {

	}
};

int main(int argc, char* argv[]) {
	ListNode* list = ListBuilder{ 1,{2,{3}} };
	return 0;
}