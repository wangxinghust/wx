#include <vector>
using namespace std;
class Solution {
public:
	// dp
	
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		if (numRows <= 0) return res;
		vector<int> level = { 1 };
		res.push_back({ level });
		int i = 2;
		while (i <= numRows) {
			vector<int> tmp;
			tmp.push_back(1);
			for (size_t j = 0; j < level.size() - 1; j++) {
				tmp.push_back(level[j] + level[j + 1]);
			}
			tmp.push_back(1);
			level.assign(tmp.begin(), tmp.end());
			res.push_back(level);
			i++;
		}
		return res;
	}

	// È¥µôlevel
	vector<vector<int>> generate2(int numRows) {
		vector<vector<int>> res;
		if (numRows <= 0) return res;
		res.push_back({ 1 });
		while (res.size() < numRows) {
			vector<int> tmp;
			tmp.push_back(1);
			for (size_t j = 0; j < res[res.size() - 1].size() - 1; j++) {
				tmp.push_back(res[res.size() - 1][j] + res[res.size() - 1][j + 1]);
			}
			tmp.push_back(1);
			res.push_back(tmp);
		}
		return res;
	}

	// Time complexity: O(numRows^2)
	// Space complexity: O(numRows^2)
};