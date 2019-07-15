#include <vector>
using namespace std;

// Runtime: 48 ms, faster than 80.72% of C++ online submissions for Reverse String.
// Memory Usage : 15.2 MB, less than 57.74 % of C++ online submissions for Reverse String.
class Solution {
public:
	void reverseString(vector<char>& s) {
		for (int i = 0; i < s.size() / 2; i++) {
			if (s[i] != s[s.size() - 1 - i])
				swap(s[i], s[s.size() - 1 - i]);
		}
	}
};