#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <map>
using namespace std;


// leetcode by dong.wang.1694
// Runtime: 24 ms, faster than 99.61% of C++ online submissions for The Skyline Problem.
// Memory Usage : 13.4 MB, less than 89.06 % of C++ online submissions for The Skyline Problem.
class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		vector<vector<int>> skyline;
		int cur = 0, cur_x, cur_h = -1, len = buildings.size();
		// first: height, seond, end time
		priority_queue<pair<int, int>> liveBlg;
		// if either some new building is not processed or live building queue is not empty
		while (cur < len || !liveBlg.empty()) {
			// next timing point to process
			cur_x = liveBlg.empty() ? buildings[cur][0] : liveBlg.top().second;

			// first check if the current tallest building will end before the next timing point
			if (cur >= len || buildings[cur][0] > cur_x) {
				// pop up the processed buildings, i.e. those have height no larger than cur_h and end before the top one
				while (!liveBlg.empty() && (liveBlg.top().second <= cur_x)) liveBlg.pop();
			}
			// if the next new building starts before the top one ends, process the new building in the vector
			else {
				cur_x = buildings[cur][0];
				// go throught all the new buildings that starts at the same point
				while (cur < len && buildings[cur][0] == cur_x) {
					// just push them in the queue
					liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
					cur++;
				}
			}
			// output the top one
			cur_h = liveBlg.empty() ? 0 : liveBlg.top().first;
			if (skyline.empty() || (skyline.back()[1] != cur_h)) skyline.push_back({ cur_x,cur_h });
		}
		return skyline;
	}
};

// 力扣 中文官解 分治
// Runtime: 196 ms, faster than 5.13% of C++ online submissions for The Skyline Problem.
// Memory Usage : 92.6 MB, less than 5.06 % of C++ online submissions for The Skyline Problem.
class Solution2 {
	// divide-and-conquer algorithm to solve skyline problem,
	// which is similar with the merge sort algorithm.

public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		int n = buildings.size();
		vector<vector<int>> output;

		// the base cases
		if (n == 0) return output;
		if (n == 1) {
			int xStart = buildings[0][0];
			int xEnd = buildings[0][1];
			int y = buildings[0][2];

			output.push_back({ xStart,y });
			output.push_back({ xEnd,0 });
			return output;
		}

		// if there is more than one building,
		// recursively divide the input into two subproblems.
		vector<vector<int>> leftSkyline, rightSkyline;
		vector<vector<int>> left(buildings.begin(), buildings.begin() + n / 2);
		leftSkyline = getSkyline(left);
		vector<vector<int>> right(buildings.begin() + n / 2, buildings.end());
		rightSkyline = getSkyline(right);

		// merge the result of subproblem together.
		return mergeSkyline(leftSkyline, rightSkyline);
	}

	// merge two skyline together
	vector<vector<int>> mergeSkyline(vector<vector<int>>& left, vector<vector<int>>& right) {
		int nL = left.size(), nR = right.size();
		int pL = 0, pR = 0;
		int currY = 0, leftY = 0, rightY = 0;
		int x, maxY;
		vector<vector<int>> output;

		// while we're in the region where both skylines are present
		while ((pL < nL) && (pR < nR)) {
			vector<int> pointL = left[pL];
			vector<int> pointR = right[pR];
			// pick up the smallest x
			if (pointL[0] < pointR[0]) {
				x = pointL[0];
				leftY = pointL[1];
				pL++;
			}
			else {
				x = pointR[0];
				rightY = pointR[1];
				pR++;
			}
			// max height (i.e. y) between both skylines
			maxY = max(leftY, rightY);
			if (currY != maxY) {
				updateOutput(output, x, maxY);
				currY = maxY;
			}
		}

		// there is only left skyline
		appendSkyline(output, left, pL, nL, currY);

		// there is only right skyline
		appendSkyline(output, right, pR, nR, currY);

		return output;
	}

	/// update the final output with the new element
	void updateOutput(vector<vector<int>>& output, int x, int y) {
		// if skyline change is not vertical
		// add the new point
		if (output.empty() || output[output.size() - 1][0] != x) {
			output.push_back({ x,y });
		}
		// if skyline change is vertical
		// update the last point
		else {
			output[output.size() - 1][1] = y;
		}
	}

	/// append the rest of the skyline elements with indice (p,n) to the final output
	void appendSkyline(vector<vector<int>>& output, vector<vector<int>>& skyline, int p, int n, int currY) {
		while (p < n) {
			vector<int> point = skyline[p];
			int x = point[0];
			int y = point[1];
			p++;

			// update output
			// if there is a skyline change
			if (currY != y) {
				updateOutput(output, x, y);
				currY = y;
			}
		}
	}
};

// leetcode by ivan_allen
// Runtime: 32 ms, faster than 87.76% of C++ online submissions for The Skyline Problem.
// Memory Usage : 16.2 MB, less than 23.61 % of C++ online submissions for The Skyline Problem.
class Solution3 {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		multiset<pair<int, int>> all; // 默认升序排列
		vector<vector<int>> res;

		for (auto& e : buildings) {
			all.insert(make_pair(e[0], -e[2])); // critical point, left corner
			all.insert(make_pair(e[1], e[2])); // critical point, right corner
		}

		multiset<int> heights({ 0 }); // 保存当前位置的所有高度,可以用来模拟最大堆，heights.rbegin()指向的元素即是最大
		vector<int> last = { 0,0 }; // 保存上一个位置的横坐标以及高度
		for (auto& p : all) {
			if (p.second < 0) heights.insert(-p.second); // 左端点，高度入堆
			else heights.erase(heights.find(p.second)); // 右端点，移除高度

			// 当前关键点，最大高度
			auto maxHeight = *heights.rbegin();

			// 当前最大高度如果不同于上一个高度，说明这是一个转折点
			if (last[1] != maxHeight) {
				// 更新last, 并加入结果集
				last[0] = p.first;
				last[1] = maxHeight;
				res.push_back(last);
			}
		}
		return res;
	}
};


//int main(int argc, char* argv[]) {
//	//vector<vector<int>> buildings = { {2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8} };
//	vector<vector<int>> buildings = { {1,2,1},{1,2,2},{1,2,3} };
//	vector<vector<int>> skyline = Solution3().getSkyline(buildings);
//	return 0;
//}