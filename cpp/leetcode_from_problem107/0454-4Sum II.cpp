#include <vector>
#include <unordered_map>
using namespace std;

// Time Limit Exceeded
class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int tuples = 0;
		for (int a = 0; a < A.size(); a++) {
			for (int b = 0; b < B.size(); b++) {
				for (int c = 0; c < C.size(); c++) {
					for (int d = 0; d < D.size(); d++) {
						if (A[a] + B[b] + C[c] + D[d] == 0) tuples++;
					}
				}
			}
		}
		return tuples;
	}
};

// leetcode by lee215
// Runtime: 244 ms, faster than 51.67% of C++ online submissions for 4Sum II.
// Memory Usage : 47.6 MB, less than 29.12 % of C++ online submissions for 4Sum II.
class Solution2 {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int> D) {
		int res = 0;
		unordered_map<int, int> abSum;
		for (int a : A) {
			for (int b : B) {
				++abSum[a + b];
			}
		}
		for (int c : C) {
			for (int d : D) {
				res += abSum[-c - d];
			}
		}
		return res;
	}
};