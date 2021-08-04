#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (s.length() < 1) {
			return "";
		}
		if (numRows == 1) {
			return s;
		}
		int circleNum = numRows * 2 - 2;
		int cycle = s.length() / circleNum + 1;
		vector<char> res;
		for (int i = 0; i < numRows; ++i) {
			if (i == 0 || i == numRows - 1) {
				for (int j = 0; j < cycle; ++j) {
					if (circleNum * j + i < s.length()) {
						res.push_back(s[circleNum * j + i]);
					}
				}
			}
			else {
				for (int j = 0; j < cycle; ++j) {
					if (circleNum * j + i < s.length()) {
						res.push_back(s[circleNum * j + i]);
					}
					if (circleNum * (j + 1) - i<s.length()) {
						res.push_back(s[circleNum * (j + 1) - i]);
					}
				}
			}
		}
		string resStr;
		resStr.insert(resStr.begin(),res.begin(), res.end());
		return resStr;
	}
};