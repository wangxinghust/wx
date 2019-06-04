#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	//leetcode Approach 2: Categorize by Count
	//Runtime: 144 ms, faster than 9.35% of C++ online submissions for Group Anagrams.
	//Memory Usage : 26.9 MB, less than 9.66 % of C++ online submissions for Group Anagrams.
	vector<vector<string>> groupAnagrams1(vector<string>& strs) {
		vector<vector<string> > ans;
		if (strs.size() == 0) return ans;
		map<string, vector<string> > hash;
		
		for (string s : strs) {
			int count[26] = { 0 };
			for (char c : s) {
				++count[c - 'a'];
			}
			string key = "";
			for (int i = 0; i < 26; ++i) {
				key += "#" + to_string(count[i]);
			}
			hash[key].push_back(s);
		}
		for (auto h : hash) {
			ans.push_back(h.second);
		}
		return ans;
	}

	vector<vector<string> > groupAnagrams2(vector<string>& strs) {
		unordered_map<string, vector<string> > map;
		for (string s : strs) {
			string t = s;
			sort(t.begin(), t.end());
			map[t].push_back(s);
		}
		vector<vector<string> > anagrams;
		for (auto p : map) {
			anagrams.push_back(p.second);
		}
		return anagrams;
	}

	vector<vector<string> > groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string> > map;
		for (string s : strs) {
			map[strSort(s)].push_back(s);
		}
		vector<vector<string> > anagrams;
		for (auto p : map) {
			anagrams.push_back(p.second);
		}
		return anagrams;
	}
	string strSort(string s) {
		int counter[26] = { 0 };
		for (char c : s) {
			counter[c - 'a']++;
		}
		string t;
		for (int c = 0; c < 26; c++) {
			t += string(counter[c], c + 'a');
		}
		return t;
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	vector<string> strs = { "eat","tea","tan","ate","nat","bat" };
//	vector<vector<string> > ans = s.groupAnagrams(strs);
//	return 0;
//}