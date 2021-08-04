#include <string>
using namespace std;
class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) return false;
		int num[26] = { 0 };
		for (int i = 0; i < s.length(); i++) {
			++num[s[i] - 'a'];
			--num[t[i] - 'a'];
		}
		for (int n : num) {
			if (n) return false;
		}
		return true;
	}
};

//int main(int argc, char* argv[]) {
//	Solution().isAnagram("anagram", "nagaram");
//	return 0;
//}