#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//Brute Force
	int maxArea(vector<int>& height) {
		int len = height.size();
		int res = min(height[0], height[1]);
		for (int i = 0; i < len - 1; ++i) {
			for (int j = i + 1; j < len; ++j) {
				int tmp = min(height[i], height[j]) * (j - i);
				if (res < tmp) {
					res = tmp;
				}
			}
		}
		return res;
	}

	//Two Pointer Approach
	int maxArea2(vector<int>& height) {
		int maxarea = 0, i = 0, j = height.size() - 1;
		while (i < j) {
			maxarea = max(maxarea, min(height[i], height[j]) * (j - i));
			if (height[i] < height[j]) {
				++i;
			}
			else {
				--j;
			}
		}
		return maxarea;
	}
};