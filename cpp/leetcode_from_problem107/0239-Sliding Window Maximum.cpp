#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Runtime: 80 ms, faster than 21.21% of C++ online submissions for Sliding Window Maximum.
// Memory Usage : 18.2 MB, less than 5.20 % of C++ online submissions for Sliding Window Maximum.
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		multiset<int> window;
		int i = 0;
		while (i < k) {
			window.insert(nums[i++]);
		}
		vector<int> ret;
		if (window.empty()) return ret;
		ret.push_back(*window.rbegin());
		for (; i < nums.size(); ++i) {
			// erase 删除与key相同的所有元素
			//window.erase(nums[i - k]);

			// 通过迭代器删除，保证每次只删除一个元素
			window.erase(window.find(nums[i - k]));
			window.insert(nums[i]);
			ret.push_back(*window.rbegin());
		}
		return ret;
	}
};

// leetcode by anmaithien
// Runtime: 52 ms, faster than 96.61% of C++ online submissions for Sliding Window Maximum.
// Memory Usage : 12.7 MB, less than 96.96 % of C++ online submissions for Sliding Window Maximum.

// 三个指针，始终维护maxIndex，当fast处的值大于maxIndex的值，更新maxIndex，当slow大于maxIndex时，maxIndex失效
// 重新计算maxIndex
class Solution2 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int length = nums.size();
		vector<int> window;

		if (length == 0) {
			return window;
		}
		int fast = k - 1;
		int maxIndex = 0;
		int slow = 0;

		// 初始化
		for (int i = 0; i <= k - 1; i++) {
			if (nums[i] >= nums[maxIndex]) {
				maxIndex = i;
			}
		}

		while(fast<length) {
			// 更新maxIndex
			if (nums[fast] >= nums[maxIndex]) {
				maxIndex = fast;
			}

			window.push_back(nums[maxIndex]);

			// 移动窗口
			slow++;
			fast++;

			// 判定maxIndex是否失效
			if (slow > maxIndex) {
				// for loop to find next maxIndex
				maxIndex = slow;
				for (int j = slow; j <= fast; j++) {
					if (nums[j] >= nums[maxIndex]) {
						maxIndex = j;
					}
				}
			}
		}

		return window;
	}
};

// https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetcode-3/
// 动态规划
// 分区，一般情况下i...j跨越两个区，因此有两个数组，一个是从分区线往左存最大值，一个是从分区线往右存最大值，因此i...j区间内的最大值时max(right[i],left[j])
class Solution3 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.empty()) return vector<int>();

		vector<int> left(nums.begin(), nums.end());
		vector<int> right(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i += k) {
			for (int j = 1; (i + j < nums.size()) && j < k; j++) {
				left[i + j] = max(left[i + j - 1], nums[i + j]);
			}
		}
		for (int i = 0; i < nums.size(); i += k) {
			int j = i + k - 1 < nums.size() ? k - 2 : nums.size() - i - 2;
			for (; j >= 0; j--) {
				right[i + j] = max(right[i + j + 1], nums[i + j]);
			}
		}

		vector<int> result(nums.size() - k + 1);
		for (int i = 0; i < result.size(); i++) {
			result[i] = max(right[i], left[i + k - 1]);
		}
		return result;
	}
};

//int main(int argc, char* argv) {
//	vector<int> nums = { -7,-8,7,5,7,1,6,0 };
//	vector<int> ret = Solution2().maxSlidingWindow(nums,4);
//	return 0;
//}