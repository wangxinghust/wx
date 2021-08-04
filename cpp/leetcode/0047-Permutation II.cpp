#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	//set去重
	//Runtime: 140 ms, faster than 7.18% of C++ online submissions for Permutations II.
	//Memory Usage : 34 MB, less than 5.01 % of C++ online submissions for Permutations II.
	vector<vector<int>> permuteUnique1(vector<int>& nums) {
		vector<vector<int> > result;
		permuteRecursive(nums, 0, result);
		set<vector<int> > resultSet(result.begin(), result.end());
		result.assign(resultSet.begin(), resultSet.end());
		return result;
	}
	void permuteRecursive(vector<int>& nums, int begin, vector<vector<int> >& result) {
		//先写终止回溯判断条件
		if (begin >= nums.size()) {
			result.push_back(nums);
			return;
		}
		for (int i = begin; i < nums.size(); ++i) {
			swap(nums[begin], nums[i]);
			permuteRecursive(nums, begin + 1, result);
			swap(nums[begin], nums[i]);
		}
	}

	//leetcode
	void recursion(vector<int> num, int i, int j, vector<vector<int> >& res) {
		if (i == j - 1) {
			res.push_back(num);
			return;
		}
		for (int k = i; k < j; k++) {
			//跳过重复
			if (i != k && num[i] == num[k]) continue;
			swap(num[i], num[k]);
			recursion(num, i + 1, j, res);
		}
	}
	vector<vector<int> > permuteUnique(vector<int>& num) {
		sort(num.begin(), num.end());
		vector<vector<int> >res;
		recursion(num, 0, num.size(), res);
		return res;
	}
};