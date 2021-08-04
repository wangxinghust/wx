#include <string>
using namespace std;
class Solution {
public:
	//Time Limit Exceeded 递归超时，换dp
	int numDecodings(string s) {
		if (s.empty()) return 0;
		int step = 0;
		numDecodingsRecursion(s, step);
		return step;
	}
	void numDecodingsRecursion(string s, int& step) {
		if (s.empty()) {
			step++;
			return;
		}
		if (s.length() >= 1 && s[0] != '0') {
			numDecodingsRecursion(s.substr(1), step);
		}
		if (s.length() >= 2 && s[0] != '0' && stoi(s.substr(0, 2)) <= 26) {
			numDecodingsRecursion(s.substr(2), step);
		}
	}

	//dp
	//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
	//Memory Usage : 8.5 MB, less than 29.23 % of C++ online submissions for Decode Ways.
	int numDecodings2(string s) {
		if (s.empty()) return 0;
		if (s.length() == 1) return s[0] != '0';
		int first = s[s.length() - 1] == '0' ? 0 : 1, second = 1;
		for (int i = s.length() - 2; i >= 0; i--) {
			int tmp = first;
			if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) first = first + second;
			else if (s[i] == '0') first = 0;//else first=first, thus omitted;
			second = tmp;
		}
		return first;
	}
};

//int main(int argc, char* argv[]) {
//	//string str = "0";
//	string str2 = "01";
//	string str3 = "1168963884134125126536966946586868418993819971673459188478711546479621135253876271366851168524933185";
//	string str4 = "12";
//	int ans = Solution().numDecodings2(str3);
//	int ans2 = Solution().numDecodings2(str2);
//	int ans3 = Solution().numDecodings2(str4);
//
//	string str5 = "226";
//	int ans4 = Solution().numDecodings2(str5);
//
//	string str6 = "0";
//	int ans6 = Solution().numDecodings2(str6);
//
//	return 0;
//}