
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class Solution {
public:
	//Runtime: 68 ms, faster than 18.91% of C++ online submissions for Populating Next Right Pointers in Each Node.
	//Memory Usage : 27.2 MB, less than 47.24 % of C++ online submissions for Populating Next Right Pointers in Each Node.
	//��Ŀ�й��޸ģ����������ܲ���
	Node* connect(Node* root) {
		// ��һ����ʼNode
		Node* start = nullptr;
		Node* current = root;
		if (root && root->left) {
			start = root->left;
		}
		while (start) {
			// �������nextָ���ҽ��
			if (current->left) {
				current->left->next = current->right;
			}
			// ��ǰ���û�����ӽ�㣬�˳�ѭ��������ʡ�Ը��ж�
			else {
				break;
			}
			// ���ҽ���nextָ��ǰnext��������
			if (current->right) {
				if (current->next) {
					current->right->next = current->next->left;
				}
			}
			// ��ǰ���û�����ӽ�㣬�˳�ѭ������ʹ������Ŀ���������ӽ��������ӽ�㣬����ʡ�Ը��ж�
			else {
				break;
			}
			// ��ǰ����next���ڣ��������ƶ�
			if (current->next) {
				current = current->next;
			}
			// �����ƶ�����һ��Ŀ�ʼλ��
			else {
				current = start;

				// ͬʱ����start��ָ��current->left
				if (current) {
					start = current->left;
				}
				else {
					start = nullptr;
				}
			}
		}
		return root;
	}

	//leetcode by Erudy
	//Runtime: 64 ms, faster than 58.31% of C++ online submissions for Populating Next Right Pointers in Each Node.
	//Memory Usage : 27.2 MB, less than 42.08 % of C++ online submissions for Populating Next Right Pointers in Each Node.
	Node* connect2(Node* root) {
		// ����ÿ�㿪ʼ���startһֱ��left����
		Node* start = root;
		// ��һ�����ʱ����ѭ��
		while (start && start->left) {
			Node* p = start;
			while (p) {
				p->left->next = p->right;
				if (p->next) {
					p->right->next = p->next->left;
				}
				p = p->next;
			}
			start = start->left;
		}
		return root;
	}
};