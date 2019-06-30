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
class Solution {
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