#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	//��0056�ԼӸĽ�
	//Runtime: 244 ms, faster than 6.69% of C++ online submissions for Insert Interval.
	//Memory Usage : 51.4 MB, less than 5.01 % of C++ online submissions for Insert Interval.
	vector<vector<int>> insert1(vector<vector<int>>& intervals, vector<int>& newInterval) {
		intervals.push_back(newInterval);
		sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
			return a[0] < b[0];
			});
		vector<vector<int> > ans;
		for (int i = 0; i < intervals.size(); ++i) {
			//��һ������||�������߲��ص�
			if (ans.empty() || ans[ans.size() - 1][1] < intervals[i][0]) {
				ans.push_back(intervals[i]);
			}
			//���ص�
			else {
				//����ǰ�ߵ���ֵ��ȡ�ϴ�ֵ
				ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
			}
		}
		return ans;
	}

	//leetcode by Wrystal
	//Runtime: 16 ms, faster than 81.04% of C++ online submissions for Insert Interval.
	//Memory Usage : 12.7 MB, less than 5.89 % of C++ online submissions for Insert Interval.
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int n = intervals.size();
		int startIdx = 0;
		//find startIdx
		while (startIdx < n) {
			if (intervals[startIdx][0] > newInterval[1]) {//��ζ��û��overlap��ֱ�Ӳ��뵱ǰλ�ü���
				intervals.insert(intervals.begin() + startIdx, newInterval);
				return intervals;
			}
			if (intervals[startIdx][1] >= newInterval[0]) break; //��ζ�����ص������ҵ�startIdx
			startIdx++;
		}

		//���startIdx��ĩβ����ζ�ű�����Ҳ�Ҳ�����˵��newInterval����ĩβ��ֱ�Ӳ嵽ĩβ����
		if (startIdx == n) { intervals.push_back(newInterval); return intervals; } 
		
		//use similar thoughts in previous problem to find start end and endIdx
		int start = min(intervals[startIdx][0], newInterval[0]); //������ֵ
		int end = max(intervals[startIdx][1], newInterval[1]); //������ֵ
		int endIdx = startIdx;

		//find endIdx & update the value of end
		while (endIdx < n && end >= intervals[endIdx][0]) {
			end = max(intervals[endIdx][1], end);
			endIdx++;
		}

		//intervals[startIdx, endIdx) should be merge to [start, end]
		intervals[startIdx] = vector<int>({ start, end });
		intervals.erase(intervals.begin() + startIdx + 1, intervals.begin() + endIdx);

		return intervals;
	}
};