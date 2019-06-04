#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	bool isNumber(string s) {
		//去掉首尾空格
		s.erase(0, s.find_first_not_of(' '));
		s.erase(s.find_last_not_of(' ') + 1);

		if (s.empty()) return false;

		int index = 0;

		int point = s.find_first_of('.');
		int exponent = s.find_first_of('e');

		if (exponent != string::npos) {
			if (point != string::npos) {
				if (exponent > point) {
					return isDouble(s.substr(0, exponent)) && isInteger(s.substr(exponent + 1));
				}
				else {
					return false;
				}
			}
			else {
				return isInteger(s.substr(0, exponent)) && isInteger(s.substr(exponent + 1));
			}
		}
		else {
			if (point != string::npos) {
				return isDouble(s);
			}
			else {
				return isInteger(s);
			}
		}
	}

	//对小数的判断
	bool isDouble(string s) {
		if (s.empty()) return false;

		if (s[0] == '+' || s[0] == '-') s.erase(0, 1);

		int index = s.find_first_of('.');
		if (index == string::npos) return false;

		if (index == 0) {
			return isUnsignedInteger(s.substr(1));
		}
		else if (index == s.size() - 1) {
			return isUnsignedInteger(s.substr(0, index));
		}
		else {
			return isUnsignedInteger(s.substr(0, index)) && isUnsignedInteger(s.substr(index + 1));
		}
	}

	bool isInteger(string s) {
		if (s.empty()) return false;

		int index = 0;
		if (s[index] == '+' || s[index] == '-') index++;
		if (index >= s.length()) return false;
		while (index < s.length()) {
			if (s[index] <= '9' && s[index] >= '0') {
				index++;
			}
			else {
				return false;
			}
		}
		return true;
	}

	bool isUnsignedInteger(string s) {
		if (s.empty()) return false;
		int index = 0;
		while (index < s.length()) {
			if (s[index] <= '9' && s[index] >= '0') {
				index++;
			}
			else {
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char* argv[]) {
	vector<string> strs = { "0"," 0.1 ","abc","1 a","2e10"," -90e3   "," 1e","e3"," 6e-1"," 99e2.5 ","53.5e93"," --6 ","-+3","95a54e53","." ,"0.." ,"3." ,"4e+" };

	vector<bool> ans = { true,true,false,false,true,true,false,false,true,false,true,false,false,false,false,false ,true ,false };

	vector<bool> test(strs.size());
	Solution s;
	for (size_t i = 0; i < strs.size(); i++)
	{
		test[i] = s.isNumber(strs[i]);
		if (test[i] ^ ans[i]) {
			int i = 0;
		}
	}

	return 0;
}