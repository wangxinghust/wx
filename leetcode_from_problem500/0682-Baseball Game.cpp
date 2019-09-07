#include <vector>
#include <string>

using namespace std;

// easy题，解析题意即可，用stack也可以，遇到+的时候需要额外保存一下原top值
class Solution {
public:
	int calPoints(vector<string>& ops) {
		vector<int> result;
		for (string str : ops) {
			if (str == "C") {
				result.pop_back();
			}
			else if (str == "D") {
				result.push_back(2 * result[result.size() - 1]);
			}
			else if (str == "+") {
				result.push_back(result[result.size() - 2] + result[result.size() - 1]);
			}
			else {
				result.push_back(stoi(str));
			}
		}
		int sum = 0;
		for (int i : result) {
			sum += i;
		}
		return sum;
	}
};