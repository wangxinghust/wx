#include <vector>
using namespace std;
class Solution {
public:
	//思路 二分查找 一个查第一个出现，一个查第二个出现的 不好实现
	vector<int> searchRange1(vector<int>& nums, int target) {

	}
	int binarySearchFirst(vector<int>& nums, int left, int right, int target) {
		int mid = left + (right - left) / 2;
		while (right >= left) {
			//TODO
			if (nums[mid-1]<nums[mid]&&nums[mid] == target) {
				return mid;
			}
			else if (nums[mid] < target) {
				left = mid + 1;
				mid = left + (right - left) / 2;
			}
			else {
				right = mid - 1;
				mid = left + (right - left) / 2;
			}
		}
		return -1;		
	}
	int binarySearchLast(vector<int>& nums, int left, int right, int target) {

	}


	//leetcode Approach 1: Linear Scan
	vector<int> searchRange2(vector<int>& nums, int target) {
		vector<int> targetRange = { -1,-1 };
		for (unsigned int i = 0; i < nums.size(); ++i) {
			if (nums[i] == target) {
				targetRange[0] = i;
				break;
			}
		}
		if (targetRange[0] == -1) {
			return targetRange;
		}
		for (int j = nums.size() - 1; j >= 0; --j) {
			if (nums[j] == target) {
				targetRange[1] = j;
				break;
			}
		}
		return targetRange;
	}

	//leetcode Approach 2: Binary Search
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> targetRange = { -1,-1 };
		int leftIndex = extremeInsertionIndex(nums, target, true);
		if (leftIndex == nums.size() || nums[leftIndex] != target) {
			return targetRange;
		}
		targetRange[0] = leftIndex;
		targetRange[1] = extremeInsertionIndex(nums, target, false) - 1;
		return targetRange;
	}
	int extremeInsertionIndex(vector<int> nums, int target, bool left) {
		int lo = 0;
		int hi = nums.size();
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] > target || (left && target == nums[mid])) {
				hi = mid;
			}
			else {
				lo = mid + 1;
			}
		}
		return lo;
	}
};

//int main(int argc, char* argv[]) {
//	return 0;
//}