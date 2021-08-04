#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	//Time Limit Exceeded
	vector<vector<int>> threeSum1(vector<int>& nums) {
		vector<vector<int> > ans;
		if (nums.size() < 3) {
			return ans;
		}
		//set<int> tmp(nums.begin(), nums.end());
		//nums.assign(tmp.begin(), tmp.end());
		set<vector<int> > st;
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				int k = j + 1;
				int sum = -(nums[i] + nums[j]);
				while (k < nums.size()) {
					if (nums[k] == sum) {
						vector<int> data = { nums[i],nums[j],nums[k] };
						sort(data.begin(), data.end());
						st.insert(data);
					}
					++k;
				}
			}
		}
		ans.assign(st.begin(), st.end());
		return ans;
	}

	//improve but wrong answer 本身还是O[n3]
	vector<vector<int>> threeSum2(vector<int>& nums) {
		vector<vector<int> > ans;
		if (nums.size() < 3) {
			return ans;
		}
		sort(nums.begin(), nums.end());
		//set<int> tmp(nums.begin(), nums.end());
		//nums.assign(tmp.begin(), tmp.end());
		for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue; //avoid repeat
			for (int j = i + 1; j < nums.size() - 1; ++j) {
				int k = j + 1;
				int tmp = -(nums[i] + nums[j]);
				//[0,0,0] 还是需要写成下一方法的if条件语句
				while (k < nums.size() && nums[k] != nums[k - 1] && nums[k] <= tmp) {
					if (nums[k] == tmp) {
						ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
					}
					++k;
				}
			}
		}
		set<vector<int> > st(ans.begin(), ans.end());
		ans.assign(st.begin(), st.end());
		return ans;
	}

	//leetcode
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		for (int i = 0; i < nums.size() && nums[i] <= 0; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue; //avoid repeat
			int j = i + 1, k = nums.size() - 1;
			while (j < k)
			{
				int tmp = nums[i] + nums[j] + nums[k];
				if (tmp > 0)
					k--;
				else if (tmp < 0)
					j++;
				else
				{
					if (k == nums.size() - 1 || (nums[j] != nums[j - 1] || nums[k] != nums[k + 1]))//avoid like[-4,-2,0,0,2,2]
					{
						res.push_back(vector<int>{nums[i], nums[j], nums[k]});
					}
					j++;
					k--;
				}
			}
		}
		return res;
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	vector<int> nums = { 0, 0, 0 };
//	vector<vector<int> > ans = s.threeSum(nums);
//	return 0;
//}