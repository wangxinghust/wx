#include <vector>
using namespace std;

// 依旧是hash表，或者有点类似静态链表
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			// 不用考虑越界，题目条件限制了数组内数据的大小
			while (nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != i + 1) result.push_back(i + 1);
		}
		return result;
	}
};