#include <queue>
using namespace std;

// definition for a node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node() {}
	Node(int _val, Node* _left, Node* _right, Node* _next) :val(_val), left(_left), right(_right), next(_next) {}
};

// Runtime: 404 ms, faster than 54.00% of C++ online submissions for Populating Next Right Pointers in Each Node II.
// Memory Usage : 67 MB, less than 30.44 % of C++ online submissions for Populating Next Right Pointers in Each Node II.
// ������ͬʱ��ά��һ��size����sizeΪ0ʱ��˵��һ��������������ýڵ�nextֵ��Ϊnullptr����ͬʱ����size
class Solution {
public:
	Node* connect(Node* root) {
		// �߽����������⽫ nullpr ��ӵ�������
		if (!root) return nullptr;
		// �������У����ڲ���
		queue<Node*> q;
		// ��ӽڵ㵽������
		q.push(root);
		// ά��һ��size��������������ÿһ��
		int size = q.size();
		while (!q.empty()) {
			Node* tmp = q.front();
			q.pop();
			if (tmp->left) q.push(tmp->left);
			if (tmp->right) q.push(tmp->right);
			// ȡ�����б�����ͬʱ���ݼ�size
			--size;
			if (!size||q.empty()) { // ò�Ʋ����ж� q.empty()
				tmp->next = nullptr; // Ҳ�������¸� next ��ֵΪ nullptr��Ĭ��ֵ���� nullptr
				size = q.size();
			}
			else {
				tmp->next = q.front();
			}
		}
		return root;
	}
};