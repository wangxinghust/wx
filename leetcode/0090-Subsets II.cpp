#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	//����0078�����ȥ��
	//Runtime: 32 ms, faster than 9.24% of C++ online submissions for Subsets II.
	//Memory Usage : 12.9 MB, less than 15.38 % of C++ online submissions for Subsets II.
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ans;
		for (int i = 0; i <= nums.size(); i++) {
			vector<vector<int>> add = combineNum(nums, nums.size(), i);
			ans.insert(ans.end(), add.begin(), add.end());
		}
		ans.push_back({});
		//ȥ��
		for (vector<int>& tmp : ans) {
			sort(tmp.begin(), tmp.end());
		}
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		return ans;
	}

	vector<vector<int>> combineNum(vector<int>& nums, int n, int k) {
		vector<vector<int>> ans;
		if (k <= 0 || n < k) {
			return ans;
		}
		if (n == k) {
			ans.push_back(nums);
			return ans;
		}
		if (k == 1) {
			for (int i : nums) {
				ans.push_back({ i });
			}
		}
		else {
			for (int i = 0; i <= n - k; i++) {
				vector<vector<int>> add;

				vector<int> tmp(nums.begin() + i + 1, nums.end());
				add = combineNum(tmp, tmp.size(), k - 1);

				for (int j = 0; j < add.size(); j++) {
					add[j].insert(add[j].begin(), nums[i]);
				}

				ans.insert(ans.end(), add.begin(), add.end());
			}
		}
		return ans;
	}

	//leetcode by mathsam
	//This is because you have two choices for each element, either putting it into the subset or not.
	//Runtime: 4 ms, faster than 99.87% of C++ online submissions for Subsets II.
	//Memory Usage : 9.4 MB, less than 54.98 % of C++ online submissions for Subsets II.
	vector<vector<int>> subsetsWithDup2(vector<int>& nums) {
		vector<vector<int> > totalset = { {} };
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size();) {
			int count = 1;// num of elements are the same ԭ�е�count����Ϊ0����Ϊ1������һ�����ж� �����Ǹ�Ϊ1�󣬿ռ�ռ�����ӣ�ʱ��ռ��δ��
			while (count + i < nums.size() && nums[count + i] == nums[i]) count++;
			int previousN = totalset.size();
			//��ԭtotalset�Ļ���������µ�Ԫ�أ����ӵļ���ԭtotalset���ӵļ���������vector<int> instance���������ظ��ģ����Էֱ��1...count��
			for (int k = 0; k < previousN; k++) {
				vector<int> instance = totalset[k];
				//���1...count��nums[i]
				for (int j = 0; j < count; j++) {
					instance.push_back(nums[i]);
					totalset.push_back(instance);
				}
			}
			i += count;
		}
		return totalset;
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	vector<vector<int>> ans;
//
//	vector<int> nums = { 1,2,2 };
//	ans = s.subsetsWithDup2(nums);
//	return 0;
//}