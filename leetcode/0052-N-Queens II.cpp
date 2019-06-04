#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	//由0051而改进，时间和空间复杂度仍较高，leetcode上有采用硬编码方式来求解的，也就是类似斐波那契数列一样，直接给出答案数组，对应查询结果
	int totalNQueens(int n) {
		vector<string> element(n, string(n, '.'));
		int methods = 0;
		backtracking(n, methods, element, 0);
		return methods;
	}
	void backtracking(int n, int& methods, vector<string> element, int tier) {
		if (tier == n) {
			methods++;
			return;
		}

		vector<string> tmp(element.begin(), element.end());

		for (int i = 0; i < n; ++i) {
			if (tmp[tier][i] == '*') {
				continue;
			}
			else {
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

				backtracking(n, methods, tmp, tier + 1);

				//返回当前层时需要恢复tmp矩阵
				tmp.assign(element.begin(), element.end());
			}
		}
	}
};