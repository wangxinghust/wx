#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

// leetcode by antdavid
// bfs经典
class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		// very interesting problem
		// It can be solved with standard BFS. The tricky idea is doing BFS of paths instead of words!
		// Then the queue becomes a queue of paths.
		vector<vector<string>> ans;
		queue<vector<string>> paths;
		unordered_set<string> wordSet(wordList.begin(), wordList.end());
		paths.push({ beginWord });
		int level = 1;
		int minLevel = INT_MAX;

		// "visited" records all the visited nodes on this level
		// these words will never be visited again after this level 
		// and should be removed from wordList. This is guaranteed
		// by the shortest path.
		unordered_set<string> visited;

		while (!paths.empty()) {
			vector<string> path = paths.front();
			paths.pop();
			if (path.size() > level) {
				// reach a new level 清除上一层访问过的，同一层可以重复
				for (string w : visited) wordSet.erase(w);
				visited.clear();
				if (path.size() > minLevel) break;
				else level = path.size();
			}
			string last = path.back();
			// find next words in wordList by changing
            // each element from 'a' to 'z'
			for (int i = 0; i < last.size(); ++i) {
				string news = last;
				for (char c = 'a'; c <= 'z'; c++) {
					news[i] = c;
					if (wordSet.find(news) != wordSet.end()) {
						// next word is in wordList
						// append this word to path
						// path will be reused in the loop
						// so copy a new path
						vector<string> newpath = path;
						newpath.push_back(news);
						visited.insert(news);
						if (news == endWord) {
							minLevel = level;
							ans.push_back(newpath);
						}
						else
							paths.push(newpath);
					}
				}
			}
		}

		return ans;
	}
};