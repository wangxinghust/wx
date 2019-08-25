#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Runtime: 4 ms, faster than 57.79% of C++ online submissions for Compare Version Numbers.
// Memory Usage : 8.4 MB, less than 91.30 % of C++ online submissions for Compare Version Numbers.
class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> data(4, 0);
		vector<int> copy(4, 0);
		int index = 0;
		int k = 0;
		for (int i = 0; index < 4 && i <= version1.size(); i++) {
			if (i == version1.size() || version1[i] == '.') {
				data[index++] = stoi(version1.substr(k, i - k));
				k = i + 1;
			}
		}
		k = 0;
		index = 0;
		for (int i = 0; index < 4 && i <= version2.size(); i++) {
			if (i == version2.size() || version2[i] == '.') {
				copy[index++] = stoi(version2.substr(k, i - k));
				k = i + 1;
			}
		}
		int j = 0;
		while (j < 4 && data[j] == copy[j]) {
			j++;
		}
		if (j == 4) {
			return 0;
		}
		else if (j != 4 && data[j] < copy[j]) {
			return -1;
		}
		else {
			return 1;
		}
	}
};

//int main() {
//	string version1 = "0.1", version2 = "1.1";
//	cout << Solution().compareVersion(version1, version2);
//	return 0;
//}