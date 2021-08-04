#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	//wrong answer
	vector<vector<int>> merge1(vector<vector<int>>& intervals) {
		vector<vector<int> > ans;
		int i = 0;
		for (; i + 1 < intervals.size(); i++) {
			if (intervals[i][1] >= intervals[i + 1][0]) {
				int tmp = i;
				for (; i < intervals.size(); i++) {
					if (i == intervals.size() - 1 || intervals[i][1] < intervals[i + 1][0]) {
						ans.push_back({ intervals[tmp][0], intervals[i][1] });
						break;
					}
				}
			}
			else {
				ans.push_back(intervals[i]);
			}
		}
		if (i == intervals.size() - 1) {
			ans.push_back(intervals[i]);
		}
		return ans;
	}

	//leetcode Approach 2: Sorting
	//Runtime: 64 ms, faster than 17.11% of C++ online submissions for Merge Intervals.
	//Memory Usage : 26.7 MB, less than 5.01 % of C++ online submissions for Merge Intervals.
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		//排序 升序排列
		sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
			return a[0] < b[0];
			});
		vector<vector<int> > ans;
		for (int i = 0; i < intervals.size(); ++i) {
			//第一个加入||或者两者不重叠
			if (ans.empty() || ans[ans.size() - 1][1] < intervals[i][0]) {
				ans.push_back(intervals[i]);
			}
			//有重叠
			else {
				//更新前者的右值，取较大值
				ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
			}
		}
		return ans;
	}

};

//int main(int argc, char* argv[]) {
//	vector<vector<int> > ans;
//	Solution s;
//	vector<vector<int> > intervals = { {1,9},{2,5},{19,20},{10,11},{12,20},{0,3},{0,1},{0,2} };
//	ans = s.merge(intervals);
//	return 0;
//}