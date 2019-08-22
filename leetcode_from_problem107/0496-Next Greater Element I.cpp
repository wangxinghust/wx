#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

// leetcode by lzl124631x
// ��ջ�������ұߵ�һ��������������map������������nums1�е���ȥ����
// ���ڶ����-1����˲��ش��ұ��Ҳ������������Ľ��������nums2�в鲻��nums1��������
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