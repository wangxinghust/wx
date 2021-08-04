
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
	//题目有过修改，大概是因此跑不过
	Node* connect(Node* root) {
		// 下一层起始Node
		Node* start = nullptr;
		Node* current = root;
		if (root && root->left) {
			start = root->left;
		}
		while (start) {
			// 将左结点的next指向右结点
			if (current->left) {
				current->left->next = current->right;
			}
			// 当前结点没有左子结点，退出循环，可以省略该判断
			else {
				break;
			}
			// 将右结点的next指向当前next结点的左结点
			if (current->right) {
				if (current->next) {
					current->right->next = current->next->left;
				}
			}
			// 当前结点没有右子结点，退出循环，即使按照题目定义有左子结点必有右子结点，可以省略该判断
			else {
				break;
			}
			// 当前结点的next存在，则下右移动
			if (current->next) {
				current = current->next;
			}
			// 否则移动到下一层的开始位置
			else {
				current = start;

				// 同时重设start，指向current->left
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
		// 设置每层开始结点start一直向left遍历
		Node* start = root;
		// 下一层存在时进入循环
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