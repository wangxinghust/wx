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
					//int tmp = p - nums.begin(); leetcode ���벻ͨ�����������޸�
					len = min(len, i - (p - nums.begin()) + 1);
				}
			}
		}
		return len;
	}

	//leetcod Approach #1: Left and Right Index [Accepted]
	int findShortestSubArray2(vector<int>& nums) {
		//lelft��ĳԪ�ص�һ�γ��ֵ�λ�ã�right���Ԫ�����һ�γ��ֵ�λ�ã�count����ֵĴ���
		map<int, int> left, right, count;
		for (int i = 0; i < nums.size(); i++) {
			int x = nums[i];
			if (left.find(x) == left.end()) left[x] = i;
			//ÿ�θ��ǣ��պ����һ��д�룬���Ǹ�Ԫ�����һ�γ��ֵ�λ��
			right[x] = i;
			//count[x]Ĭ��Ϊ0����������պô�0��1���������Լ�1
			++count[x];
		}
		//ans���Ϊnums.size();
		int ans = nums.size();
		//lambda���ʽ
		auto p = max_element(count.begin(), count.end(), [](pair<int, int> a, pair<int, int> b) {
			return a.second < b.second; });
		int degree = p->second;
		//����������degree��ȵ������У�����Ӧ��С����
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