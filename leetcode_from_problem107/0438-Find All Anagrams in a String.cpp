#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// leetcode by chaoyanghe
// 滑动窗口算法 总结 用于子串搜索问题
// https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92007/Sliding-Window-algorithm-template-to-solve-all-the-Leetcode-substring-search-problem.

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		// init a collection to save the result
		vector<int> result;
		if (p.length() > s.length()) return result;

		// create a hashmap to save the Characters of the target substring
		unordered_map<char, int> hashmap;
		for (char c : p) {
			++hashmap[c];
		}
		// maintain a counter to check whether match the target string
		int counter = hashmap.size();// must be the map size, NOT the string size because the char may be duplicates

		// two pointers: begin - left pointer of the window; end - right pointer of the window
		int begin = 0, end = 0;
		// 没有作用的两行，由模板改来
		//int head = 0;
		//int len = INT_MAX;

		// loop at the begining of the source string
		while (end < s.length()) {
			// get a character
			char c = s[end];
			if (hashmap.find(c) != hashmap.end()) {
				--hashmap[c];
				if (hashmap[c] == 0) --counter;// modify the counter
			}
			end++;

			// increase begin pointer to make it invalid again
			while (counter == 0) {
				// ***be careful here : choose the char at begin pointer, NOT the end pointer
				char tempc = s[begin];
				if (hashmap.find(tempc) != hashmap.end()) {
					++hashmap[tempc];
					if (hashmap[tempc] > 0) ++counter;// modify the counter
				}
				// save the result if find a target
				if (end - begin == p.length()) {
					result.push_back(begin);
				}
				++begin;
			}
		}
		return result;
	}
};