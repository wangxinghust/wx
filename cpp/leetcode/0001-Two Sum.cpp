#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int behind;
		int ahead;
		vector<int> res;
		if (nums.size() < 2)
		{
			return res;
		}
		for (behind = 0; behind < nums.size(); ++behind)
		{
			for (ahead = behind + 1; ahead < nums.size(); ++ahead)
			{
				if (nums[behind] + nums[ahead] == target)
				{
					res.push_back(behind);
					res.push_back(ahead);
					return res;
				}
			}
		}
		return res;
	}
};