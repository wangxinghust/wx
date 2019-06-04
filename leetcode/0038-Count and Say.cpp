#include <string>
using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		string ans = "1";
		for (int i = 1; i < n; ++i) {
			ans = countAndSayOnce(ans);
		}
		return ans;
	}
	string countAndSayOnce(string begin) {
		string end;
		char ch = begin[0];
		int count = 1;
		for (int i = 1; i < begin.length(); ++i) {
			if (begin[i] == begin[i - 1]) ++count;
			else {
				end += to_string(count) + begin[i - 1];
				count = 1;
			}
		}
		return end += to_string(count) + begin[begin.length() - 1];
	}
};


//int main(int argc, char* argv[]) {
//	Solution s;
//	string end = s.countAndSay(4);
//	return 0;
//}