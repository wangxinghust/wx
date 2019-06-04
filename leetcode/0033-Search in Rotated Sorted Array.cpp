#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int search1(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		if (target == nums[0]) return 0;
		if (target > nums[0]) {
			for (unsigned int i = 1; i < nums.size(); ++i) {
				if (nums[i] == target) return i;
				if (nums[i] > target) return -1;
			}
		}
		else {
			for (int i = nums.size() - 1; i >= 0; --i) {
				if (nums[i] == target) return i;
				if (nums[i] < target) return -1;
			}
		}
		return -1;
	}


	//leetcode binary search
	int findGreatestValueIndex(vector<int> & nums, int left, int right) {
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

	int binarySearch(vector<int> & nums, int left, int right, int target) {
		int mid = left + (right - left) / 2;
		while (right >= left) {
			if (nums[mid] == target) {
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

	int search(vector<int> & nums, int target) {
		int midP = findGreatestValueIndex(nums, 0, nums.size() - 1);
		//max用于去除-1的情况
		return max(binarySearch(nums, 0, midP, target), binarySearch(nums, midP + 1, nums.size() - 1, target));
	}
};


//int main(int argc, char* argv[]) {
//	vector<int> nums = { 0 };
//	Solution s;
//	int index = s.search(nums, 0);
//	return 0;
//}