#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	//Runtime: 8 ms, faster than 27.14% of C++ online submissions for Restore IP Addresses.
	//Memory Usage : 9.3 MB, less than 7.79 % of C++ online submissions for Restore IP Addresses.
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		recursion("", s, res, 1);
		return res;
	}
	void recursion(string before, string after, vector<string>& res, int step) {
		if (step == 4) {
			if (after.length() == 1 || (after.length() <= 3 && after[0] != '0' && stoi(after) <= 255)) {
				res.push_back(before + after);
			}
			return;
		}
		if (after.length() >= 7 - step && after[0] != '0') {
			if (stoi(after.substr(0, 3)) <= 255) {
				recursion(before + after.substr(0, 3) + ".", after.substr(3), res, step + 1);
			}
		}
		if (after.length() >= 6 - step && after[0] != '0') {
			recursion(before + after.substr(0, 2) + ".", after.substr(2), res, step + 1);
		}
		if (after.length() >= 5 - step) {
			recursion(before + after.substr(0, 1) + ".", after.substr(1), res, step + 1);
		}
	}
};

//int main(int argc, char* argv[]) {
//	//string str = "25525511135";
//	string str = "010010";
//	vector<string> res = Solution().restoreIpAddresses(str);
//	return 0;
//}