#include <string>
using namespace std;

class Solution {
public:
	//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Length of Last Word.
	//Memory Usage : 8.9 MB, less than 52.03 % of C++ online submissions for Length of Last Word.
	int lengthOfLastWord(string s) {
		if (s.empty()) return 0;

		//清除s末尾的空格
		s.erase(s.find_last_not_of(' ') + 1);

		//找到末尾的第一个空格，返回长度值
		auto pos = s.find_last_of(' ');
		if (pos == std::string::npos) {
			return s.length();
		}
		else {
			return s.length() - pos - 1;
		}
	}
};