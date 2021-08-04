#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

// 回溯法 Time Limit Exceeded
class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		int rows = board.size();
		int cols = board.empty() ? 0 : board[0].size();
		map<char, vector<pair<int, int>>> charPos;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				charPos[board[i][j]].push_back({ i,j });
			}
		}
		vector<string> ret;
		for (string word : words) {
			for (auto pos : charPos[word[0]]) {
				vector<vector<bool>> visit(rows, vector<bool>(cols, false));
				if (backtracking(board, rows, cols, visit, pos.first, pos.second, 0, word)) {
					ret.push_back(word);
					break;
				}
			}
		}
		return ret;
	}
private:
	bool backtracking(vector<vector<char>>& board, int& rows, int& cols, vector<vector<bool>>& visit, int x, int y, int cur, string& word) {
		if (cur == word.length()) return true;
		if (x < 0 || x >= rows || y < 0 || y >= cols || visit[x][y] || board[x][y] != word[cur]) return false;
		visit[x][y] = true;
		if (backtracking(board, rows, cols, visit, x + 1, y, cur + 1, word) ||
			backtracking(board, rows, cols, visit, x - 1, y, cur + 1, word) ||
			backtracking(board, rows, cols, visit, x, y + 1, cur + 1, word) ||
			backtracking(board, rows, cols, visit, x, y - 1, cur + 1, word)) {
			return true;
		}
		visit[x][y] = false;
		return false;
	}
};

// leetcode by rabeeh: DFS+Trie
// Runtime: 184 ms, faster than 34.65% of C++ online submissions for Word Search II.
// Memory Usage : 95.7 MB, less than 15.14 % of C++ online submissions for Word Search II.
class TrieNode {
public:
	bool is_end;
	vector<TrieNode*> children;
	TrieNode() {
		is_end = false;
		children = vector<TrieNode*>(26, NULL);
	}
};

class Trie {
public:
	TrieNode* getRoot() { return root; }
	Trie(vector<string>& words) {
		root = new TrieNode();
		for (int i = 0; i < words.size(); ++i)
			addWord(words[i]);
	}
	void addWord(const string& word) {
		TrieNode* cur = root;
		for (int i = 0; i < word.size(); ++i) {
			int index = word[i] - 'a';
			if (cur->children[index] == NULL)
				cur->children[index] = new TrieNode();
			cur = cur->children[index];
		}
		cur->is_end = true;
	}
private:
	TrieNode* root;
};

class Solution2 {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		Trie* trie = new Trie(words);
		TrieNode* root = trie->getRoot();
		set<string> result_set;
		for (int x = 0; x < board.size(); ++x) {
			for (int y = 0; y < board[0].size(); ++y) {
				findWords(board, x, y, root, "", result_set);
			}
		}
		vector<string> result(result_set.begin(), result_set.end());
		return result;
	}
private:
	void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, set<string>& result) {
		if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == ' ') return;
		// 在trie里存在
		if (root->children[board[x][y] - 'a'] != NULL) {
			word = word + board[x][y];
			// 同时移动root
			root = root->children[board[x][y] - 'a'];
			if (root->is_end) result.insert(word);
			char c = board[x][y];
			// 空格表示遍历过，遍历完再恢复，相当于bool标记
			board[x][y] = ' ';
			findWords(board, x + 1, y, root, word, result);
			findWords(board, x - 1, y, root, word, result);
			findWords(board, x, y + 1, root, word, result);
			findWords(board, x, y - 1, root, word, result);
			board[x][y] = c;
		}
	}
};


//int main(int argc, char* argv[]) {
//	vector<vector<char>> board = { {'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'} };
//	vector<string> words = { "oath","pea","eat","rain" };
//	auto ret = Solution2().findWords(board, words);
//	return 0;
//}