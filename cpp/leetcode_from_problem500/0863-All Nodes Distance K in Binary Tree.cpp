#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Approach 1: Annotate Parent
// Runtime: 12 ms, faster than 31.18% of C++ online submissions for All Nodes Distance K in Binary Tree.
// Memory Usage : 18.5 MB, less than 18.18 % of C++ online submissions for All Nodes Distance K in Binary Tree.
class Solution {
	unordered_map<TreeNode*, TreeNode*> parent;
	unordered_set<TreeNode*> visit;
	vector<int> ans;
	// We first do a depth first search where we annotate every node with information about it's parent.
	void dfs(TreeNode* node, TreeNode* par) {
		if (node != NULL) {
			parent[node] = par;
			dfs(node->left, node);
			dfs(node->right, node);
		}
	}
	// Using dfs to find K distance node, visited nodes will be recorded.
	void dfs2(TreeNode* node, int K) {
		if (visit.find(node) != visit.end()) {
			return;
		}
		visit.insert(node);
		if (K == 0) {
			ans.push_back(node->val);
			return;
		}
		if (node->left) {
			dfs2(node->left, K - 1);
		}
		if (node->right) {
			dfs2(node->right, K - 1);
		}
		TreeNode* p = parent[node];
		if (p) {
			dfs2(p, K - 1);
		}
	}
public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		if (!root || !target) return {};

		dfs(root, NULL);

		dfs2(target, K);

		return ans;
	}
};

// Approach 2:Percolate Distance
// Runtime: 8 ms, faster than 68.43% of C++ online submissions for All Nodes Distance K in Binary Tree.
// Memory Usage : 15.1 MB, less than 100.00 % of C++ online submissions for All Nodes Distance K in Binary Tree.
class Solution2 {
	vector<int> ans;
	TreeNode* target_glo;
	int K_glo;
public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		target_glo = target;
		K_glo = K;
		dfs(root);
		return ans;
	}
	// Return vertex distance from node to target if exists, else -1
	// Vertex distance: the number of vertices on the path from node to target
	int dfs(TreeNode* node) {
		// 递归终止条件：叶结点后的空结点，或target结点，加入target是叶结点，需遍历所有结点
		if (node == NULL) {
			return -1;
		}
		else if (node == target_glo) {
			subtree_add(node, 0);
			return 1;
		}
		else {
			int L = dfs(node->left), R = dfs(node->right);
			// 如果 target 在左子树，添加右结点子树距其 K-(L+1) 的结点的值到ans中
			if (L != -1) {
				if (L == K_glo) ans.push_back(node->val);
				subtree_add(node->right, L + 1);
				return L + 1;
			}
			else if (R != -1) {
				if (R == K_glo) ans.push_back(node->val);
				subtree_add(node->left, R + 1);
				return R + 1;
			}
			else {
				return -1;
			}
		}
	}
	// Add all nodes 'K - dist' from the node to answer.
	void subtree_add(TreeNode* node, int dist) {
		if (node == NULL) return;
		if (dist == K_glo) {
			ans.push_back(node->val);
		}
		else {
			subtree_add(node->left, dist + 1);
			subtree_add(node->right, dist + 1);
		}
	}
};

//int main(int argc, char* argv[]) {
//	return 0;
//}