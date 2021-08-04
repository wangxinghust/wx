#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	//暴力解 Time Limit Exceeded
	int largestRectangleArea(vector<int>& heights) {
		int minHeight, maxArea = 0;
		for (int i = 0; i < heights.size(); i++) {
			int j = i;
			minHeight = heights[j];
			maxArea = max(maxArea, heights[j]);
			j++;
			for (; j < heights.size(); j++) {
				minHeight = min(minHeight, heights[j]);
				maxArea = max(maxArea, (j - i + 1)*minHeight);
			}
		}
		return maxArea;
	}


	//leetcode by undercover76
	//Scan from left to right to compute left[], which represents the left most boundary of current height.
	//Scan from right to left to compute right[], which represents the right most boundary of current height.
	//Scan from left to right again to compute rectangle area based on the height of that each position.

	//Runtime: 12 ms, faster than 95.48% of C++ online submissions for Largest Rectangle in Histogram.
	//Memory Usage : 10.5 MB, less than 40.87 % of C++ online submissions for Largest Rectangle in Histogram.
	int largestRectangleArea2(vector<int>& heights) {
		//validate input
		if (heights.size() == 0) return 0;

		//init
		int n = heights.size();
		vector<int> left(n);
		vector<int> right(n);
		int result = 0;

		//build left
		left[0] = 0;
		for (int i = 1; i < n; i++) {
			int currentLeft = i - 1;
			//不断向左遍历，直至某个值小于heights[i]
			while (currentLeft >= 0 && heights[currentLeft] >= heights[i]) {
				currentLeft = left[currentLeft] - 1;
			}
			left[i] = currentLeft + 1;
		}

		//build right
		right[n - 1] = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			int currentRight = i + 1;
			//同上
			while (currentRight < n && heights[currentRight] >= heights[i]) {
				currentRight = right[currentRight] + 1;
			}
			right[i] = currentRight - 1;
		}

		//compare height
		for (int i = 0; i < n; i++) {
			result = max(result, (right[i] - left[i] + 1) * heights[i]);
		}

		return result;
	}

};

//int main(int argc, char *argv[]) {
//	Solution s;
//	vector<int> heights = { 2,1,5,6,2,3 };
//	int ans = s.largestRectangleArea2(heights);
//	return 0;
//}