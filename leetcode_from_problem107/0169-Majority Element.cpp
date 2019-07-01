#include <vector>
#include <algorithm>
using namespace std;

// Approach 1: Brute Force

// Approach 2: HashMap

// Approach 3: Sorting
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};

// Approach 4: Randomization

// Approach 5:Divide and Conquer

class Solution2 {
private:
	int countInRange(vector<int>& nums, int num, int lo, int hi) {
		int count = 0;
		for (int i = lo; i <= hi; i++) {
			if (nums[i] == num) {
				count++;
			}
		}
		return count;
	}
	int majorityElementRec(vector<int>& nums, int lo, int hi) {
		// base case; the only element in an array of size 1 is the majority element.
		if (lo == hi) return nums[lo];
		// recurse on left and right halves of this slice.
		int mid = (hi - lo) / 2 + lo;
		int left = majorityElementRec(nums, lo, mid);
		int right = majorityElementRec(nums, mid + 1, hi);
		// if the two halves agree on the majority element, return it.
		if (left == right) return left;
		// otherwise, count each element and return the "winner".
		int leftCount = countInRange(nums, left, lo, hi);
		int rightCount = countInRange(nums, right, lo, hi);
		return leftCount > rightCount ? left : right;
	}
public:
	int majorityElement(vector<int>& nums) {
		return majorityElementRec(nums, 0, nums.size() - 1);
	}
};

// Approach 6: Boyer-Moore Voting Algorithm
class Solution3 {
public:
	int majorityElement(vector<int>& nums) {
		int count = 0;
		int candidate = NULL;
		for (int i = 0; i < nums.size(); i++) {
			if (count == 0) candidate = nums[i];
			count += (nums[i] == candidate) ? 1 : -1;
		}
		return candidate;
	}
};

// 剑指offer 基于快排的改进
// Runtime: 28 ms, faster than 33.77% of C++ online submissions for Majority Element.
// Memory Usage : 11 MB, less than 54.03 % of C++ online submissions for Majority Element.
class Solution4 {
public:
	int majorityElement(vector<int>& nums) {
		int length = nums.size();
		int middle = length >> 1;
		int start = 0;
		int end = length - 1;
		int index = partition(nums, length, start, end);
		while (index != middle) {
			if (index > middle) {
				end = index - 1;
				index = partition(nums, length, start, end);
			}
			else {
				start = index + 1;
				index = partition(nums, length, start, end);
			}
		}
		int result = nums[middle];
		return result;
	}
private:
	int partition(vector<int>& nums, int length, int start, int end) {
		if (nums.empty() || length <= 0 || start < 0 || end >= length) 
			// return -1;leetcode中不支持异常
			throw new exception("Invalid Parameters");

		int index = RandomInRange(start, end);
		swap(nums[index], nums[end]);

		int small = start - 1;
		for (index = start; index < end; ++index) {
			if (nums[index] < nums[end]) {
				++small;
				if (small != index) {
					swap(nums[index], nums[small]);
				}
			}
		}
		++small;
		swap(nums[small], nums[end]);
		return small;
	}
	int RandomInRange(int start,int end) {
		if (start == end) return start;
		return (rand() % (end - start)) + start;
	}
};