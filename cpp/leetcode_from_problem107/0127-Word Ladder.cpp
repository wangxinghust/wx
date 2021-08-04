#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
	// leetcode approach 1: Breadth First Search
	// Runtime: 188 ms, faster than 50.63% of C++ online submissions for Word Ladder.
	// Memory Usage : 29.4 MB, less than 11.84 % of C++ online submissions for Word Ladder.
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

		// since all words are of same length
		int L = beginWord.length();

		// dictionary to hold combination of words that can be formed,
		// from any given word. by changing one letter at a time.
		map<string, vector<string>> allComboDict;

		for (string word : wordList) {
			for (int i = 0; i < L; i++) {
				// key is the generic word
				// value is a list of words which have the same intermediate generic word
				string newWord = word.substr(0, i) + '*' + (i + 1 < L ? word.substr(i + 1) : "");
				allComboDict[newWord].push_back(word);
			}
		}

		// queue for BFS
		queue<pair<string, int>> Q;
		Q.push(make_pair(beginWord, 1));

		// visited to make sure we don't repeat processing same word.
		map<string, bool> visited;
		visited[beginWord] = true;

		while (!Q.empty()) {
			auto node = Q.front();
			Q.pop();
			string word = node.first;
			int level = node.second;
			for (int i = 0; i < L; i++) {
				// intermediate words for current word
				string newWord = word.substr(0, i) + '*' + (i + 1 < L ? word.substr(i + 1) : "");

				// next states are all the words which share the same intermediate state.
				for (string adjacentWord : allComboDict[newWord]) {
					// if at any point if we find what we are looking for
					// i.e the end word - we can return with the answer.
					if (adjacentWord == endWord) {
						return level + 1;
					}
					// otherwise, add it to the BFS Queue. Also mark it visited
					if (visited.find(adjacentWord) == visited.end()) {
						visited[adjacentWord] = true;
						Q.push(make_pair(adjacentWord, level + 1));
					}
				}
			}
		}

		return 0;
	}
};

// leetcode Approach 2: Bidirectional Breadth First Search
// Runtime: 108 ms, faster than 64.36% of C++ online submissions for Word Ladder.
// Memory Usage : 27.4 MB, less than 15.00 % of C++ online submissions for Word Ladder.

class Solution2 {
private:
	int L;
	map<string, vector<string>> allComboDict;

	// &不可缺少 否则退出时Q visited othersVisited不会被修改
	int visitWordNode(queue<pair<string, int>>& Q, map<string, int>& visited, map<string, int>& othersVisited) {
		pair<string, int> node = Q.front();
		Q.pop();
		string word = node.first;
		int level = node.second;

		for (int i = 0; i < this->L; i++) {
			// intermediate words for current word
			string newWord = word.substr(0, i) + '*' + word.substr(i + 1);

			// next states are all the words which share the same intermediate state.
			for (string adjacentWord : allComboDict[newWord]) {
				// if at any point if we find what we are looking for
				// i.e. the end word - we can return with the answer.
				if (othersVisited.find(adjacentWord) != othersVisited.end()) {
					return level + othersVisited[adjacentWord];
				}

				if (visited.find(adjacentWord) == visited.end()) {
					// save the level as the value of the dictionary, to save number of hops.
					visited[adjacentWord] = level + 1;
					Q.push(make_pair(adjacentWord, level + 1));
				}
			}
		}

		return -1;
	}
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (find(wordList.begin(), wordList.end(), endWord) == end(wordList)) return 0;

		this->L = beginWord.length();
		for (auto word : wordList) {
			for (int i = 0; i < L; i++) {
				// key is the generic word
				// value is a list of words which have the same intermediate generic word.
				string newWord = word.substr(0, i) + '*' + word.substr(i + 1);
				this->allComboDict[newWord].push_back(word);
			}
		}

		// queue for birdirectional BFS
		// BFS starting from beginWord
		queue<pair<string, int>> Q_begin;
		// BFS starting form endWord
		queue<pair<string, int>> Q_end;

		Q_begin.push(make_pair(beginWord, 1));
		Q_end.push(make_pair(endWord, 1));

		// visited to make sure we don't repeat processing same word.
		map<string, int> visitedBegin;
		map<string, int> visitedEnd;
		visitedBegin[beginWord] = 1;
		visitedEnd[endWord] = 1;

		while (!Q_begin.empty() && !Q_end.empty()) {
			// one hop from begin word
			int ans = visitWordNode(Q_begin, visitedBegin, visitedEnd);
			if (ans > -1) {
				return ans;
			}

			// one hop from end word
			ans = visitWordNode(Q_end, visitedEnd, visitedBegin);
			if (ans > -1) {
				return ans;
			}
		}

		return 0;
	}
};

//int main(int argc, char* argv[]) {
//	string beginWord = "hit";
//	string endWord = "cog";
//	vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
//	int ans = Solution().ladderLength(beginWord, endWord, wordList);
//
//	return 0;
//}