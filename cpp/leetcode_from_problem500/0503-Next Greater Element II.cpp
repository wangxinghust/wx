#include <stack>
#include <vector>
using namespace std;

// Runtime: 88 ms, faster than 74.65% of C++ online submissions for Next Greater Element II.
// Memory Usage : 12.5 MB, less than 55.56 % of C++ online submissions for Next Greater Element II.
class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		// 用栈来存下标，而不是nums里的数据，比较的时候也是比较nums[s.top()]和nums[i]即可
		stack<int> s;
		vector<int> ans(nums.size(), -1);

		// 第一次遍历后是一个单调栈
		for (int i = 0; i < nums.size(); i++) {
			while (!s.empty() && nums[s.top()] < nums[i]) {
				ans[s.top()] = nums[i];
				s.pop();
			}
			s.push(i);
		}

		// 第二次遍历，仅需要对单调栈里剩余的从大到小的数进行弹出即可，最后剩下的，默认值为-1，不必再往栈里存无效的值
		for (int i = 0; i < nums.size(); i++) {
			while (!s.empty() && nums[s.top()] < nums[i]) {
				ans[s.top()] = nums[i];
				s.pop();
			}
		}

		return ans;
	}
};

// Approach #3 Using Stack [Accepted]
// 从右往左遍历，比栈顶值小，入栈，比栈顶值大，弹出栈内的值，直到比栈顶值小，或栈为空
// 依旧是单调栈，依旧是遍历两遍
// Runtime: 88 ms, faster than 74.65% of C++ online submissions for Next Greater Element II.
// Memory Usage : 12.5 MB, less than 55.56 % of C++ online submissions for Next Greater Element II.
class Solution2 {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		stack<int> s;
		vector<int> ans(nums.size(), -1);
		for (int i = (int)nums.size() - 1; i >= 0; i--) {
			while (!s.empty() && nums[s.top()] <= nums[i]) {
				s.pop();
			}
			if (!s.empty()) ans[i] = nums[s.top()];
			s.push(i);
		}

		for (int i = (int)nums.size() - 1; i >= 0; i--) {
			while (!s.empty() && nums[s.top()] <= nums[i]) {
				s.pop();
			}
			if (!s.empty()) ans[i] = nums[s.top()];
			s.push(i);
		}

		//for (int i = (int)nums.size() - 1; i >= 0; i--) {
		//	// 已有结果的，再存入栈中也不会改变结果，直接跳过即可 
		//	// 由测试用例[31,-41,59,26,-53,58,97,-93,-23,84]可知，有的结果值是负数，不是-1，不能用这个来跳过，只能再次重复
		//	if (ans[i] > -1) continue;
		//	while (!s.empty() && nums[s.top()] <= nums[i]) {
		//		s.pop();
		//	}
		//	if (!s.empty()) ans[i] = nums[s.top()];
		//	// 也不用再存进去，存进去的能改变ans的都已经起作用了
		//}
		return ans;
	}
};

//int main() {
//	vector<int> nums = { 1,2,1 };
//	auto ans = Solution2().nextGreaterElements(nums);
//	for (int n : ans) {
//		printf("%d ", n);
//	}
//	return 0;
//}