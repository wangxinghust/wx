#include <string>
#include <algorithm>
using namespace std;


// Runtime: 164 ms, faster than 28.05% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
// Memory Usage : 54.6 MB, less than 12.99 % of C++ online submissions for Longest Substring with At Least K Repeating Characters.
class Solution {
public:
	int longestSubstring(string s, int k) {
		if (s.length() < k)
			return 0;
		if (k == 1)
			return s.length();
		int letters[26] = { 0 };
		for (int i = 0; i < s.length(); i++) {
			++letters[s[i] - 'a'];
		}
		for (int i = 0; i < s.length(); i++) {
			if (letters[s[i] - 'a'] && letters[s[i] - 'a'] < k)
				return max(longestSubstring(s.substr(0, i), k), longestSubstring(s.substr(i + 1), k));
		}
		return s.length();
	}
};

// leetcode by zestypanda
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
// Memory Usage : 8.9 MB, less than 55.80 % of C++ online submissions for Longest Substring with At Least K Repeating Characters.
class Solution2 {
public:
	int longestSubstring(string s, int k) {
		int n = s.size();
		return helper(s, 0, n - 1, k);
	}
private:
	// looking for longest string within index range [l,r]
	int helper(string& s, int l, int r, int k) {
		int mp[26] = { 0 };
		for (int i = l; i <= r; ++i)
			++mp[s[i] - 'a'];
		// check whether the whole string meets requirement
		bool pass = true;
		for (int i = 0; i < 26 && pass; ++i) {
			if (mp[i] && mp[i] < k)
				pass = false;
		}
		if (pass)
			return r - l + 1;
		// using all characters with occurrence > 0 && < k to divide the string 
		int i = l, ans = 0;
		for (int j = l; j <= r; ++j) {
			if (mp[s[j] - 'a'] && mp[s[j] - 'a'] < k) {
				ans = max(ans, helper(s, i, j - 1, k));
				i = j + 1;
			}
		}
		return max(ans, helper(s, i, r, k));
	}
};

//int main(int argc, char* argv[]) {
//	int ret = Solution2().longestSubstring("aaabb", 3);
//	int ret2 = Solution().longestSubstring("ababbc", 2);
//	return 0;
//}