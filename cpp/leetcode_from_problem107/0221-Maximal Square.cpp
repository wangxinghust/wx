#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	//leetcode Approach 1: Brute Force
	//Runtime: 20 ms, faster than 94.00% of C++ online submissions for Maximal Square.
	//Memory Usage : 10.7 MB, less than 87.55 % of C++ online submissions for Maximal Square.
	int maximalSquare1(vector<vector<char>>& matrix) {
		int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
		int maxsqlen = 0;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (matrix[i][j] == '1') {
					int sqlen = 1;
					bool flag = true;
					while (sqlen + i < rows && sqlen + j < cols && flag) {
						//只往左上角遍历，对所有的角遍历后，总可以找到包裹1最大方阵的右下角
						for (int k = j; k <= sqlen + j; ++k) {
							if (matrix[i + sqlen][k] == '0') {
								flag = false;
								break;
							}
						}
						for (int k = i; k <= sqlen + i; ++k) {
							if (matrix[k][j + sqlen] == '0') {
								flag = false;
								break;
							}
						}
						if (flag) {
							sqlen++;
						}
					}
					if (maxsqlen < sqlen) {
						maxsqlen = sqlen;
					}
				}
			}
		}
		return maxsqlen * maxsqlen;
	}


	//Approach #2 (Dynamic Programming) [Accepted]
	//同上，dp遍历，每个点存右下角能包裹的最大方阵：dp(i,j)=min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1.
	//Runtime: 24 ms, faster than 56.03% of C++ online submissions for Maximal Square.
	//Memory Usage : 11.4 MB, less than 39.61 % of C++ online submissions for Maximal Square.
	//dp算法还没暴力求解快，也是尴尬
	int maximalSquare2(vector<vector<char>>& matrix) {
		int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
		//加一行和一列空的，方便遍历
		vector<vector<int> > dp(rows + 1, vector<int>(cols + 1));
		int maxsqlen = 0;
		for (int i = 1; i <= rows; ++i) {
			for (int j = 1; j <= cols; ++j) {
				//这里-1，实际上表示dp数组对应原数组所在的位置
				if (matrix[i - 1][j - 1] == '1') {
					dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
					maxsqlen = max(maxsqlen, dp[i][j]);
				}
			}
		}
		return maxsqlen * maxsqlen;
	}


	//Approach #3 (Better Dynamic Programming) [Accepted]
	//Runtime: 16 ms, faster than 97.69% of C++ online submissions for Maximal Square.
	//Memory Usage : 10.8 MB, less than 84.14 % of C++ online submissions for Maximal Square.
	int maximalSquare(vector<vector<char>>& matrix) {
		int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
		vector<int> dp(cols + 1);
		int maxsqlen = 0, prev = 0;
		for (int i = 1; i <= rows; ++i) {
			for (int j = 1; j <= cols; ++j) {
				//暂存更新前的dp[j] 可是dp的prev没有存啊，还是有点奇怪
				int temp = dp[j];
				if (matrix[i - 1][j - 1] == '1') {
					//求dp[1]的时候，用的prev好像存的是上一次的dp[cols]的值啊 这岂不是有问题，应该把prev=0的式子放到i的循环里？ 但是能AC啊
					dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
					maxsqlen = max(maxsqlen, dp[j]);
				}
				else {
					dp[j] = 0;
				}
				//dp更新后，将原dp值存入prev，就是下一次使用时的左上角值了
				prev = temp;
			}
		}
		return maxsqlen * maxsqlen;
	}
};