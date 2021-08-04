#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0) return 0;
		if (nums[0] >= target) return 0;
		if (nums[nums.size() - 1] < target) return nums.size();
		int ahead = 0, rear = nums.size() - 1;
		while (ahead < rear) {
			int mid = ahead + (rear - ahead) / 2;
			if (nums[mid] < target) ahead = mid + 1;
			else if (nums[mid] == target) return mid;
			else rear = mid;
		}
		return rear;
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> nums = { 1,3,5,6 };
//	int target = 2;
//	Solution s;
//	int index = s.searchInsert(nums, target);
//	return 0;
//}