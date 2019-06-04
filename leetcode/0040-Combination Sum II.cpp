#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
				combinationSum2(candidates, target - candidates[i], res, combination, i + 1);//修改处，传入i还是i+1
				combination.pop_back();
			}
	}
};