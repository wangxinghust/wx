#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	//由0033改进而来，findGreatestValueIndex()找最大值的下标，对两段分别进行二分查找，判断是否存在target
	//Runtime: 8 ms, faster than 87.83% of C++ online submissions for Search in Rotated Sorted Array II.
	//Memory Usage : 9.3 MB, less than 5.08 % of C++ online submissions for Search in Rotated Sorted Array II.
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 0) return false;
		int midP = findGreatestValueIndex(nums, 0, nums.size() - 1);
		if (midP == -1) {
			return binarySearch(nums, 0, nums.size() - 1, target);
		}
		else {
			return binarySearch(nums, 0, midP, target) || binarySearch(nums, midP + 1, nums.size() - 1, target);
		}
	}

	int findGreatestValueIndex(vector<int>& nums, int left, int right) {
		if (right == left)
			return -1;
		int mid = left + (right - left) / 2;
		while (right >= left) {
			if (nums[mid] > nums[mid + 1]) {
				return mid;
			}
			else {
				//max用于去除-1的情况
				return max(findGreatestValueIndex(nums, left, mid), findGreatestValueIndex(nums, mid + 1, right));
			}
		}
		return -1;
	}

	int binarySearch(vector<int>& nums, int left, int right, int target) {

		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				return true;
			}
			else if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return false;
	}

	//leetcode by amcalhoun84 : Binary Search with Sliding Window
	//Runtime: 4 ms, faster than 99.80% of C++ online submissions for Search in Rotated Sorted Array II.
	//Memory Usage : 8.8 MB, less than 36.41 % of C++ online submissions for Search in Rotated Sorted Array II.
	bool search2(vector<int>& nums, int target) {
		if (!nums.size()) return false;

		int left = 0;
		int right = nums.size() - 1;

		if (nums[left] == target || nums[right] == target) return true;

		while (left <= right) {
			int mid = (left + right) >> 1;

			if (nums[mid] == target) return true;

			//binary search
			//左区 收缩right
			if (nums[left] <= target && nums[mid] > target) { // this would be a normal situation...
				right = mid - 1;
			}
			//右区 收缩left
			else if (nums[right] >= target && nums[mid] < target) {
				left = mid + 1;
			}

			//sliding window
			//步进left，直至跨越最高点
			else if (nums[right] >= target && nums[mid] > target) {
				left++;
			}
			//步进right，直至跨越最高点
			else {
				right--;
			}
		}

		return false;
	}
};