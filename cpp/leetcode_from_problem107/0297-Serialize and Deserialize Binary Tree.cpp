#include <string>
#include <queue>
#include <sstream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		queue<TreeNode*> q;
		string tree = "";
		if (root == NULL) return "null";
		else {
			tree += to_string(root->val);
		}
		q.push(root);
		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();

			if (t->left == NULL) {
				if (!q.empty() || t->right != NULL)
					tree += ",null"; // 序列化的时候还是会出现倒数第二个叶子节点增加两个null值的情况
			}
			else {
				tree += ',' + to_string(t->left->val);
				q.push(t->left);
			}
			if (t->right == NULL) {
				if (!q.empty())
					tree += ",null";
			}
			else {
				tree += ',' + to_string(t->right->val);
				q.push(t->right);
			}
		}
		return tree;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data == "null") return NULL;
		TreeNode* root;
		int i = 0;
		for (int j = i; j <= data.length(); j++) {
			if (j == data.length() || data[j] == ',') {
				string valStr = data.substr(i, j - i);
				root = new TreeNode(stoi(valStr));
				i = j + 1;
				break;
			}
		}
		queue<TreeNode*> q;
		q.push(root);
		while (i < data.length()) {
			for (int j = i; j <= data.length(); j++) {
				if (j == data.length() || data[j] == ',') {
					string valStr = data.substr(i, j - i);
					TreeNode* node = q.front();
					if (valStr == "null") {
						node->left = NULL;
					}
					else {
						TreeNode* left = new TreeNode(stoi(valStr));
						node->left = left;
						q.push(left);
					}
					i = j + 1;
					break;
				}
			}
			for (int j = i; j <= data.length(); j++) {
				if (j == data.length() || data[j] == ',') {
					string valStr = data.substr(i, j - i);
					TreeNode* node = q.front();
					q.pop();
					if (valStr == "null") {
						node->right = NULL;
					}
					else {
						TreeNode* right = new TreeNode(stoi(valStr));
						node->right = right;
						q.push(right);
					}
					i = j + 1;
					break;
				}
			}
		}
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// leetcode by StefanPochmann: preorder
class Codec2 {
public:

	string serialize(TreeNode* root) {
		ostringstream out;
		serialize(root, out);
		return out.str();
	}

	TreeNode* deserialize(string data) {
		std::istringstream in(data);
		return deserialize(in);
	}

private:

	void serialize(TreeNode* root, ostringstream& out) {
		if (root) {
			out << root->val << ' ';
			serialize(root->left, out);
			serialize(root->right, out);
		}
		else {
			out << "# ";
		}
	}

	TreeNode* deserialize(istringstream& in) {
		string val;
		in >> val;
		if (val == "#")
			return nullptr;
		TreeNode* root = new TreeNode(stoi(val));
		root->left = deserialize(in);
		root->right = deserialize(in);
		return root;
	}
};

//int main(int argc, char* argv[]) {
//	TreeNode* root = new TreeNode(1);
//	TreeNode* node = new TreeNode(2);
//	TreeNode* node2 = new TreeNode(3);
//	TreeNode* node3 = new TreeNode(4);
//	TreeNode* node4 = new TreeNode(5);
//	root->left = node;
//	root->right = node2;
//	node2->left = node3;
//	node2->right = node4;
//
//	string tree = Codec2().serialize(root);
//	TreeNode* ret = Codec2().deserialize(tree);
//
//	return 0;
//}