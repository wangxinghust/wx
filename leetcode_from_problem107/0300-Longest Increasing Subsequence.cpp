#include <vector>
#include <algorithm>
using namespace std;

// dp 从后往前
// Runtime: 68 ms, faster than 6.39% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage : 8.7 MB, less than 46.50 % of C++ online submissions for Longest Increasing Subsequence.
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> len(nums.size(), 1);
		for (int i = len.size() - 2; i >= 0; --i) {
			for (int j = i + 1; j < len.size(); ++j) len[i] = (nums[i] < nums[j] ? max(len[i], len[j] + 1) : len[i]);
		}
		return *max_element(len.begin(), len.end());
	}
};

// Approach 3: Dynamic Porgramming 从前往后
class Solution2 {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> len(nums.size());
		len[0] = 1;
		int maxans = 1;
		for (int i = 1; i < len.size(); i++) {
			int maxval = 0;
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					maxval = max(maxval, len[j]);
				}
			}
			len[i] = maxval + 1;
			maxans = max(maxans, len[i]);
		}
		return maxans;
	}
};

// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
// Runtime: 4 ms, faster than 93.21% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage : 8.6 MB, less than 73.94 % of C++ online submissions for Longest Increasing Subsequence.
class Solution3{
private:
	// Binary search (note boundaries in the caller) 
	int ceilIndex(vector<int>& v, int l, int r, int key) {
		while (r - l > 1) {
			int m = l + (r - l) / 2;
			if (v[m] >= key)
				r = m;
			else
				l = m;
		}
		return r;
	}
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int> tail(nums.size(), 0);
		int length = 1; // always points empty slot in tail

		tail[0] = nums[0];
		for (size_t i = 1; i < nums.size(); i++) {
			// new smallest value
			if (nums[i] < tail[0])
				tail[0] = nums[i];
			// nums[i] extends largest subsequence
			else if (nums[i] > tail[length - 1])
				tail[length++] = nums[i];

			// nums[i] will become end candidate of an existing
			// subsequence or Throw away larger elements in all
			// LIS, to make room for upcoming greater elements
			// than nums[i] (and also, nums[i] would have already
			// append in one of LIS, identify the location
			// and replace it)
			else
				tail[ceilIndex(tail, -1, length - 1, nums[i])] = nums[i];
		}
		return length;
	}
};

// alternate implementation using upper_bound() in C++:
// Runtime: 4 ms, faster than 93.21% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage : 8.5 MB, less than 89.60 % of C++ online submissions for Longest Increasing Subsequence.
class Solution4 {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int> tail(nums.size(), 0);
		int length = 1; // always points empty slot in tail

		tail[0] = nums[0];
		for (size_t i = 1; i < nums.size(); i++) {
			if (nums[i] > tail[length - 1])
				tail[length++] = nums[i];
			else {
				// to check whether the element is not present before hand
				auto it = find(tail.begin(), tail.begin() + length, nums[i]);
				if (it != tail.begin() + length) {
					continue;
				}
				// if not present change the tail element to nums[i]
				it = upper_bound(tail.begin(), tail.begin() + length, nums[i]); // upper_bound:Returns an iterator pointing to the first element in the range [first, last) that is greater than value, or last if no such element is found.
				*it = nums[i];
			}
		}

		return length;
	}
};

//int main(int argc, char* argv[]) {
//	//vector<int> nums = { -2,-1 };
//	vector<int> nums = { 10,9,2,5,3,7,101,18 };
//	int ret = Solution().lengthOfLIS(nums);
//	return 0;
//}