#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

// Runtime: 4 ms, faster than 99.93% of C++ online submissions for Longest Consecutive Sequence.
// Memory Usage : 8.9 MB, less than 99.79 % of C++ online submissions for Longest Consecutive Sequence.
// 但是排序算法 time complexity 是 O(nlogn) 不符合题目要求
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.empty()) return 0;
		sort(nums.begin(), nums.end());

		int len = 1;
		int maxLen = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1] + 1) len++;
			else if (nums[i] > nums[i - 1] + 1) {
				maxLen = max(maxLen, len);
				len = 1;
			}
		}
		return len > maxLen ? len : maxLen;
	}
};

// leetcode Approach 3: HashSet and Intelligent Sequence Building
// Runtime: 20 ms, faster than 22.91% of C++ online submissions for Longest Consecutive Sequence.
// Memory Usage : 10.3 MB, less than 20.45 % of C++ online submissions for Longest Consecutive Sequence.
class Solution2 {
public:
	int longestConsecutive(vector<int>& nums) {
		// Set is implemented as balanced tree structure that is why it is possible to maintain an order between the
		// element(by specific tree traversal). Time complexity of set operation is O(Log n) while for unordered_set, it is O(1).
		unordered_set<int> num_set;
		for (int num : nums) {
			num_set.insert(num);
		}

		int longestStreak = 0;

		for (int num : num_set) {
			if (num_set.find(num - 1) == num_set.end()) {
				int currentNum = num;
				int currentStreak = 1;

				while (num_set.find(currentNum + 1) != num_set.end()) {
					++currentNum;
					++currentStreak;
				}
				
				longestStreak = max(longestStreak, currentStreak);
			}
		}

		return longestStreak;
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> nums = { 100,4,200,1,3,2 };
//	//vector<int> nums = { 0,0,1,-1 };
//	int ans = Solution2().longestConsecutive(nums);
//	return 0;
//}