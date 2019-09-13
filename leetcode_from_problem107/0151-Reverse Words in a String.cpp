#include <string>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		int start = s.find_first_not_of(' ');
		if (start == -1) return "";
		int end = s.find_last_not_of(' ');

		s = s.substr(start, end - start + 1);

		string result = "";
		int left = 0;
		while (left < s.size()) {
			int right = s.find_first_of(' ', left);
			if (right == -1) {
				right = s.size();
			}
			result = s.substr(left, right - left) + " " + result;

			left = s.find_first_not_of(' ', right);
		}
		result.pop_back();
		return result;
	}
};

//int main() {
//	string s = "a";
//	string result = Solution().reverseWords(s);
//	return 0;
//}