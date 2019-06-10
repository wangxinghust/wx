#include <string>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
	//leetcode Approach 1: Sliding Window
	//Runtime: 40 ms, faster than 24.24% of C++ online submissions for Minimum Window Substring.
	//Memory Usage : 10.3 MB, less than 42.13 % of C++ online submissions for Minimum Window Substring.
	string minWindow(string s, string t) {
		if (s.empty() || t.empty()) {
			return "";
		}

		//Dictionary which keeps a count of all the unique characters in t.
		map<char, int> dictT;
		for (int i = 0; i < t.length(); i++) {
			if (dictT.find(t[i]) == dictT.end()) {
				dictT[t[i]] = 1;
			}
			else {
				dictT[t[i]]++;
			}
		}

		//Number of unique characters in t, which need to be present in the desired window.
		int required = dictT.size();

		//Left and Right pointer
		int l = 0, r = 0;

		// formed is used to keep track of how many unique characters in t
		// are present in the current window in its desired frequency.
		// e.g. if t is "AABC" then the window must have two A's, one B and one C.
		// Thus formed would be = 3 when all these conditions are met.
		int formed = 0;

		// Dictionary which keeps a count of all the unique characters in the current window.
		map<char, int> windowCounts;

		// ans list of the form (window length, left, right)
		int ans[] = { -1,0,0 };

		while (r < s.length()) {
			// Add one character from the right to the window
			char c = s[r];
			if (windowCounts.find(c) == windowCounts.end()) {
				windowCounts[c] = 1;
			}
			else {
				windowCounts[c]++;
			}

			// If the frequency of the current character added equals to the
			// desired count in t then increment the formed count by 1.
			if (dictT.find(c) != dictT.end() && windowCounts[c] == dictT[c]) {
				formed++;
			}

			// Try and contract the window till the point where it ceases to be 'desirable'.
			while (l <= r && formed == required) {
				c = s[l];
				if (ans[0] == -1 || r - l + 1 < ans[0]) {
					ans[0] = r - l + 1;
					ans[1] = l;
					ans[2] = r;
				}

				// The character at the position pointed by the
				// `Left` pointer is no longer a part of the window.
				windowCounts[c]--;
				if (dictT.find(c) != dictT.end() && windowCounts[c] < dictT[c]) {
					formed--;
				}

				// Move the left pointer ahead, this would help to look for a new window.
				l++;
			}

			// Keep expanding the window once we are done contracting.
			r++;
		}

		return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
	}

	// leetcode Approach 2: Optimized Sliding Window 优化思路是对的，但是对map的操作很费时间，同时增加了vector<pair<int,char>>的空间占用
	//Runtime: 52 ms, faster than 14.11% of C++ online submissions for Minimum Window Substring.
	//Memory Usage : 12.5 MB, less than 27.82 % of C++ online submissions for Minimum Window Substring.
	string minWindow2(string s, string t) {
		if (s.empty() || t.empty()) {
			return "";
		}

		//Dictionary which keeps a count of all the unique characters in t.
		map<char, int> dictT;
		for (int i = 0; i < t.length(); i++) {
			if (dictT.find(t[i]) == dictT.end()) {
				dictT[t[i]] = 1;
			}
			else {
				dictT[t[i]]++;
			}
		}

		//Number of unique characters in t, which need to be present in the desired window.
		int required = dictT.size();

		// Filter all the characters from s into a new list along with their index.
		// The filtering criteria is that the character should be present in t.
		vector<pair<int, char>> filteredS;
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (dictT.find(c) != dictT.end()) {
				filteredS.push_back({ i,c });
			}
		}

		//Left and Right pointer
		int l = 0, r = 0;

		// formed is used to keep track of how many unique characters in t
		// are present in the current window in its desired frequency.
		// e.g. if t is "AABC" then the window must have two A's, one B and one C.
		// Thus formed would be = 3 when all these conditions are met.
		int formed = 0;

		// Dictionary which keeps a count of all the unique characters in the current window.
		map<char, int> windowCounts;

		// ans list of the form (window length, left, right)
		int ans[] = { -1,0,0 };

		// Look for the characters only in the filtered list instead of entire s.
		// This helps to reduce our search.
		// Hence, we follow the sliding window approach on as small list.
		while (r < filteredS.size()) {
			// Add one character from the right to the window
			char c = filteredS[r].second;
			if (windowCounts.find(c) == windowCounts.end()) {
				windowCounts[c] = 1;
			}
			else {
				windowCounts[c]++;
			}

			// If the frequency of the current character added equals to the
			// desired count in t then increment the formed count by 1.
			if (dictT.find(c) != dictT.end() && windowCounts[c] == dictT[c]) {
				formed++;
			}

			// Try and contract the window till the point where it ceases to be 'desirable'.
			while (l <= r && formed == required) {
				c = filteredS[l].second;

				int end = filteredS[r].first;
				int start = filteredS[l].first;
				if (ans[0] == -1 || end - start + 1 < ans[0]) {
					ans[0] = end - start + 1;
					ans[1] = start;
					ans[2] = end;
				}

				// The character at the position pointed by the
				// `Left` pointer is no longer a part of the window.
				windowCounts[c]--;
				if (dictT.find(c) != dictT.end() && windowCounts[c] < dictT[c]) {
					formed--;
				}

				// Move the left pointer ahead, this would help to look for a new window.
				l++;
			}

			// Keep expanding the window once we are done contracting.
			r++;
		}

		return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
	}
};

//int main(int argc, char* argv[]) {
//	string s = "abc";//"ADOBECODEBANC";
//	string t = "b";//"ABC";
//	Solution solu;
//	string ans = solu.minWindow2(s, t);
//	return 0;
//}