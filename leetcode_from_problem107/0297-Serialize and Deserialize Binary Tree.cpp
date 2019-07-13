#include <string>
#include <queue>
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
			tree += root->val;
		}
		q.push(root);
		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();

			if (t->left == NULL) {
				if (!q.empty() || t->right != NULL)
					tree += ",null";
			}
			else {
				tree += ',' + t->left->val;
				q.push(t->left);
			}
			if (t->right == NULL) {
				if (!q.empty())
					tree += ",null";
			}
			else {
				tree += ',' + t->right->val;
				q.push(t->right);
			}
		}
		return tree;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {

	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));