#include <vector>
#include <time.h>
using namespace std;

// Approach #2 Fisher-Yates Algorithm [Accepted]
// Runtime: 208 ms, faster than 62.17% of C++ online submissions for Shuffle an Array.
// Memory Usage : 30.2 MB, less than 30.58 % of C++ online submissions for Shuffle an Array.
class Solution {
	vector<int> arr;
	vector<int> original;
public:
	Solution(vector<int>& nums) {
		arr = nums;
		original.assign(nums.begin(), nums.end());
	}
	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		arr.assign(original.begin(), original.end());
		return original;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		for (int i = arr.size() - 1; i >= 0; --i) {
			swap(arr[i], arr[rand() % (i + 1)]);
		}
		return arr;
	}
};

// leetcode by fittaoee: Fisher-Yates Algorithm
class Solution2 {
	vector<int> arr, idx;
public:
	Solution2(vector<int> nums) {
		// Seeds the pseudo-random number generator used by std::rand() with the value time(NULL)
		srand(time(NULL));
		arr.resize(nums.size());
		idx.resize(nums.size());
		for (int i = 0; i < nums.size(); i++) {
			arr[i] = nums[i];
			idx[i] = nums[i];
		}
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		for (int i = 0; i < arr.size(); i++)
			arr[i] = idx[i];
		return arr;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		int i, j;
		for (i = arr.size() - 1; i > 0; i--) {
			j = rand() % (i + 1);
			swap(arr[i], arr[j]);
		}
		return arr;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */