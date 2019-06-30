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

};