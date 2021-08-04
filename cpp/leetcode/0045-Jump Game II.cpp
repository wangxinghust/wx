#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//dp but Time Limit Exceeded
	int jump1(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1) return 0;
		vector<int> step(len - 1);
		for (int i = len - 2; i >= 0; --i) {
			if (len - i - 1 <= nums[i]) {
				step[i] = 1;
			}
			else {
				int minStep = INT_MAX;
				for (int j = i + 1; j <= i + nums[i]; ++j) {
					minStep = min(minStep, step[j]);
				}
				if (minStep == INT_MAX) {
					step[i] = INT_MAX;
				}
				else {
					step[i] = 1 + minStep;
				}
			}
		}
		return step[0];
	}


	int jump2(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1) return 0;
		int step = 0;
		for (int i = 0; i < len;) {
			if (i + nums[i] + 1 >= len) {
				++step;
				break;
			}
			int furthestIndex = i;
			int maxDistance = 0;
			for (int j = i+1; j <= i + nums[i]; ++j) {
				if (maxDistance <= nums[j] + j - i) {
					maxDistance = nums[j] + j - i;
					furthestIndex = j;
				}
			}
			++step;
			i = furthestIndex;
			//防止死循环可以加个判断nums[i]==0，如果跳到0了，说明这个0跳不过去，也就是无解了
		}
		return step;
	}

	//one loop based on Greedy
	int jump(vector<int>& nums) {
		int jumps = 0, curEnd = 0, curFarthest = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			curFarthest = max(curFarthest, i + nums[i]);
			if (i == curEnd) {
				jumps++;
				curEnd = curFarthest;
			}
		}
		return jumps;
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> nums = { 5,9,3,2,1,0,2,3,3,1,0,0 };
//	Solution s;
//	int step = s.jump(nums);
//	return 0;
//}