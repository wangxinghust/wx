#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> ans;
		vector<string> element(n, string(n, '.'));
		vector<int> position(n);

		backtracking(n, ans, element, 0, position);
		return ans;
	}
	void backtracking(int n, vector<vector<string>>& ans, vector<string> element, int tier, vector<int>& position) {
		if (tier == n) {
			vector<string> tmpStr;
			for (int i = 0; i < n; ++i) {
				string str(n, '.');
				str[position[i]] = 'Q';
				tmpStr.push_back(str);
			}
			ans.push_back(tmpStr);
			return;
		}

		vector<string> tmp(element.begin(), element.end());
		
		for (int i = 0; i < n; ++i) {
			if (tmp[tier][i] == '*') {
				continue;
			}
			else {
				position[tier] = i;

				//竖线
				for (int j = tier + 1; j < n; ++j) {
					tmp[j][i] = '*';
				}
				//左斜线
				for (int j = tier + 1, k = i - 1; j < n && k >= 0; ++j, --k) {
					tmp[j][k] = '*';
				}
				//右斜线
				for (int j = tier + 1, k = i + 1; j < n && k < n; ++j, ++k) {
					tmp[j][k] = '*';
				}

				backtracking(n, ans, tmp, tier + 1, position);
				
				//返回当前层时需要恢复tmp矩阵
				tmp.assign(element.begin(), element.end());
			}
		}

	}
};


//int main(int argc, char* argv[]) {
//	Solution s;
//	vector<vector<string>> ans = s.solveNQueens(4);
//	return 0;
//}