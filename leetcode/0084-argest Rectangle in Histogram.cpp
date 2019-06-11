#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	//±©Á¦½â Time Limit Exceeded
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
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> heights = { 2,1,5,6,2,3 };
	int ans = s.largestRectangleArea(heights);
	return 0;
}