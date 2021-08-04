#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

// definition for a binary tree node.
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

// leetcode Approach 1: Recursive Approach
// Runtime: 20 ms, faster than 81.31% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
// Memory Usage : 16.5 MB, less than 93.38 % of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// traverse the tree
		recurseTree(root, p, q);
		return ans;
	}
private:
	TreeNode* ans;
	bool recurseTree(TreeNode* currentNode, TreeNode* p, TreeNode* q) {
		// if reached the end of a branch, return false.
		if (currentNode == nullptr) return false;
		// left recursion. if left recursion returns true, set left = 1 else 0
		int left = recurseTree(currentNode->left, p, q) ? 1 : 0;
		// right recursion.
		int right = recurseTree(currentNode->right, p, q) ? 1 : 0;
		// if the current node is one of q or q
		int mid = (currentNode == p || currentNode == q) ? 1 : 0;
		// if any two of the flags left, right or mid become true
		if (mid + left + right >= 2) {
			ans = currentNode;
		}
		// return true if any one of the three bool values is true
		return mid + left + right > 0;
	}
};

// Approach 2: Iterative using parent pointers
// Runtime: 52 ms, faster than 7.37% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
// Memory Usage : 20 MB, less than 14.76 % of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
class Solution2 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// stack for tree traversal
		queue<TreeNode*> qu;
		// hashmap for parent pointers
		map<TreeNode*, TreeNode*> parent;

		parent.insert({ root,nullptr });
		qu.push(root);

		// iterate until we find both the nodes p and q
		while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
			TreeNode* node = qu.front(); qu.pop();
			// while traversing the tree, keep saving the parent pointers.
			if (node->left != nullptr) {
				parent.insert({ node->left,node });
				qu.push(node->left);
			}
			if (node->right != nullptr) {
				parent.insert({ node->right,node });
				qu.push(node->right);
			}
		}

		// ancestor set() for node p.
		set<TreeNode*> ancestor;
		// process all ancestor for node p using parent pointers.
		while (p != nullptr) {
			ancestor.insert(p);
			p = parent[p];
		}

		// the first ancestor of q which appears in p's ancestor set() is their lowest common ancestor.
		while (ancestor.find(q) == ancestor.end())
			q = parent[q];
		return q;
	}
};