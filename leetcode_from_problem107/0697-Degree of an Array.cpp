#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		if (nums.empty()) return 0;
		int degree = 1;
		int len = 1;
		map<int, int> numsCount;
		for (int i = 0; i < nums.size(); i++) {
			if (++numsCount[nums[i]] >= degree) {
				if (numsCount[nums[i]] > degree) {
					degree = numsCount[nums[i]];
					auto p = find(nums.begin(), nums.end(), nums[i]);
					len = i - (p - nums.begin()) + 1;
				}
				else {
					auto p = find(nums.begin(), nums.end(), nums[i]);
					//int tmp = p - nums.begin(); leetcode 编译不通过，需这样修改
					len = min(len, i - (p - nums.begin()) + 1);
				}
			}
		}
		return len;
	}

	//leetcod Approach #1: Left and Right Index [Accepted]
	int findShortestSubArray2(vector<int>& nums) {
		//lelft存某元素第一次出现的位置，right存该元素最后一次出现的位置，count存出现的次数
		map<int, int> left, right, count;
		for (int i = 0; i < nums.size(); i++) {
			int x = nums[i];
			if (left.find(x) == left.end()) left[x] = i;
			//每次覆盖，刚好最后一次写入，即是该元素最后一次出现的位置
			right[x] = i;
			//count[x]默认为0，不存在则刚好从0加1，存在则自加1
			++count[x];
		}
		//ans最大为nums.size();
		int ans = nums.size();
		//lambda表达式
		auto p = max_element(count.begin(), count.end(), [](pair<int, int> a, pair<int, int> b) {
			return a.second < b.second; });
		int degree = p->second;
		//遍历，找与degree相等的子序列，求相应最小长度
		for (auto it : count) {
			if (it.second == degree) {
				ans = min(ans, right[it.first] - left[it.first] + 1);
			}
		}
		return ans;
	}
};

//int main(int argc, char* argv[]) {
//	//vector<int> nums = { 1,2,2,3,1,4,2 };
//	vector<int> nums = { 2,1,1,2,1,3,3,3,1,3,1,3,2 };
//	int ans = Solution().findShortestSubArray2(nums);
//	return 0;
//}