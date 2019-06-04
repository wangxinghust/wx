#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	//wrong
	vector<vector<int>> combinationSum1(vector<int>& candidates, int target) {
		vector<vector<int> > ans;
		if (candidates.size() == 0) return ans;
		int index = searchInsert(candidates, candidates.size() - 1, target);
		if (candidates[index] == target) {
			ans.push_back(vector<int> {target});
		}
		while (--index >= 0) {
			vector<int> tmp(candidates.begin(), candidates.begin() + index);
			vector<vector<int> > mid = combinationSum(tmp, target - candidates[index]);

			if (mid.size() == 0) {
				continue;
			}
			for (auto row : mid) {
				row.push_back(candidates[index - 1]);
			}
			ans.insert(ans.end(), mid.begin(), mid.end());
		}
		return ans;
	}

	int searchInsert(vector<int>& nums, int end, int target) {
		if (nums.size() == 0) return 0;
		if (nums[0] >= target) return 0;
		if (nums[end] < target) return end + 1;
		int ahead = 0, rear = end;
		while (ahead < rear) {
			int mid = ahead + (rear - ahead) / 2;
			if (nums[mid] < target) ahead = mid + 1;
			else if (nums[mid] == target) return mid;
			else rear = mid;
		}
		return rear;
	}



	//leetcode
	//Accepted 16ms c++ solution use backtracking for Combination Sum:
public:
	std::vector<std::vector<int> > combinationSum(std::vector<int>& candidates, int target) {
		//升序排列
		std::sort(candidates.begin(), candidates.end());
		std::vector<std::vector<int> > res;
		//暂存已经放入的数字，用引用的形式添加和传递
		std::vector<int> combination;
		combinationSum(candidates, target, res, combination, 0);
		return res;
	}
private:
	void combinationSum(std::vector<int>& candidates, int target, std::vector<std::vector<int> >& res, std::vector<int>& combination, int begin) {
		//回溯终止条件 target==0
		if (!target) {
			res.push_back(combination);
			return;
		}
		for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i) {
			combination.push_back(candidates[i]);
			combinationSum(candidates, target - candidates[i], res, combination, i);
			combination.pop_back();
		}
	}

	//Accepted 12ms c++ solution use backtracking for Combination Sum II: 实际上是包括后续题目的答案。。。。稍作修改以适应此题即可
	//best solution！ comment by wx
public:
	std::vector<std::vector<int> > combinationSum2(std::vector<int>& candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		std::vector<std::vector<int> > res;
		std::vector<int> combination;
		combinationSum2(candidates, target, res, combination, 0);
		return res;
	}
private:
	void combinationSum2(std::vector<int>& candidates, int target, std::vector<std::vector<int> >& res, std::vector<int>& combination, int begin) {
		if (!target) {
			res.push_back(combination);
			return;
		}
		for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
			//排除下一个重复的，类似前面某道题里的排序
			if (i == begin || candidates[i] != candidates[i - 1]) {
				combination.push_back(candidates[i]);
				combinationSum2(candidates, target - candidates[i], res, combination, i);//修改处，传入i还是i+1
				combination.pop_back();
			}
	}

	//Accepted 0ms c++ solution use backtracking for Combination Sum III :
	//但是candidates都没有了，着实看不懂
public:
	std::vector<std::vector<int> > combinationSum3(int k, int n) {
		std::vector<std::vector<int> > res;
		std::vector<int> combination;
		combinationSum3(n, res, combination, 1, k);
		return res;
	}
private:
	void combinationSum3(int target, std::vector<std::vector<int> >& res, std::vector<int>& combination, int begin, int need) {
		if (!target) {
			res.push_back(combination);
			return;
		}
		else if (!need)
			return;
		for (int i = begin; i != 10 && target >= i * need + need * (need - 1) / 2; ++i) {
			combination.push_back(i);
			combinationSum3(target - i, res, combination, i + 1, need - 1);
			combination.pop_back();
		}
	}
};


//int main(int argc, char* argv[]) {
//	vector<vector<int> > ans;
//	vector<int> candidates = { 2,3,6,7 };
//	Solution s;
//	ans = s.combinationSum2(candidates, 7);
//	return 0;
//}