#include <vector>
using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty()) return 0;
		int left = 0, right = nums.size() - 1;
		if (nums[left] < nums[right]) return nums[left];
		while (left < right - 1) {
			int mid = left + ((right - left) >> 1);
			if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
				for (int i = left + 1; i <= right; i++) {
					if (nums[i] < nums[i - 1]) {
						return nums[i];
					}
				}
				return nums[right];
			}
			if (nums[mid] > nums[right])
				left = mid;
			if (nums[mid] < nums[left])
				right = mid;
		}
		return nums[right];
	}
};