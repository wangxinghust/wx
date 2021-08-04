#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// Approach #1 Sorting
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		// ensure that n is the last index
		if (nums[nums.size() - 1] != nums.size()) return nums.size();
		// ensure that 0 is at the first index
		else if (nums[0] != 0) return 0;
		// if we get here, then the missing number is on the range (0,n)
		for (int i = 1; i < nums.size(); i++) {
			int expectedNum = nums[i - 1] + 1;
			if (nums[i] != expectedNum) return expectedNum;
		}

		// array was not missing any numsbers
		return -1;
	}
};

// Approach #2 HashSet
class Solution2 {
public:
	int missingNumber(vector<int>& nums) {
		set<int> numSet(nums.begin(), nums.end());

		int expectedNumCount = nums.size() + 1;
		for (int number = 0; number < expectedNumCount; number++)
			if (numSet.find(number) == numSet.end()) return number;

		return -1;
	}
};

// Approach #3 Bit Manipulation
// 利用异或
class Solution3 {
public:
	int missingNumber(vector<int>& nums) {
		int missing = nums.size();
		for (int i = 0; i < nums.size(); i++) {
			missing ^= i ^ nums[i];
		}
		return missing;
	}
};

// Approach #4 Gauss' Formula
class Solution4 {
public:
	int missingNumber(vector<int>& nums) {
		int expectedSum = nums.size() * (nums.size() + 1) / 2;
		int actualSum = 0;
		for (int num : nums) actualSum += num;
		return expectedSum - actualSum;
	}
};

// in case of overflow, approach 4 can be optimized as follow
class Solution5 {
public:
	int missingNumber(vector<int>& nums) {
		int result = 0;
		for (int i = 0; i < nums.size(); ++i) {
			result += (i + 1) - nums[i];
		}
		return result;
	}
};