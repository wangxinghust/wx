#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

// leetcode by lzl124631x
// 用栈来计算右边第一个比其大的数，用map来存结果，方便nums1中的数去查找
// 由于都输出-1，因此不必存右边找不到比其大的数的结果，当做nums2中查不到nums1的数即可
// Runtime: 12 ms, faster than 61.96% of C++ online submissions for Next Greater Element I.
// Memory Usage : 9.6 MB, less than 52.63 % of C++ online submissions for Next Greater Element I.
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		stack<int> s;
		unordered_map<int, int> m;
		for (int n : nums2) {
			while (s.size() && s.top() < n) {
				m[s.top()] = n;
				s.pop();
			}
			s.push(n);
		}
		vector<int> ans(nums1.size(), -1);
		for (int i = 0; i < nums1.size(); i++) {
			auto itr = m.find(nums1[i]);
			if (itr != m.end()) {
				ans[i] = itr->second;
			}
		}
		return ans;
	}
};