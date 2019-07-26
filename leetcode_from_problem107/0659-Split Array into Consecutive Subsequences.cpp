#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// leetcode by JadenPan: Greedy
// https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/106493/C%2B%2B-O(n)-solution-two-pass
// Runtime: 112 ms, faster than 70.32% of C++ online submissions for Split Array into Consecutive Subsequences.
// Memory Usage : 18 MB, less than 57.27 % of C++ online submissions for Split Array into Consecutive Subsequences.
class Solution {
public:
	bool isPossible(vector<int>& nums) {
		unordered_map<int, int> cnt, tails;
		// in first pass we count the frequencies of all numbers and record them in cnt
		for (int& i : nums) cnt[i]++;
		for (int& i : nums) {
			if (!cnt[i]) continue;
			cnt[i]--;
			// 判断能否追加到已有序列里
			if (tails[i - 1] > 0) {
				tails[i - 1]--;
				tails[i]++;
			}
			// 遇到不能追加到原序列的，先消耗其后两个数的库存
			else if (cnt[i + 1] && cnt[i + 2]) {
				cnt[i + 1]--;
				cnt[i + 2]--;
				tails[i + 2]++;
			}
			else return false;
		}
		return true;
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> nums = { 1,2,3,4,4,4,5,5,5,6,6,6 };
//	bool b = Solution().isPossible(nums);
//	return 0;
//}