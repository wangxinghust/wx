#include <stack>
#include <vector>
using namespace std;

// Runtime: 88 ms, faster than 74.65% of C++ online submissions for Next Greater Element II.
// Memory Usage : 12.5 MB, less than 55.56 % of C++ online submissions for Next Greater Element II.
class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		// ��ջ�����±꣬������nums������ݣ��Ƚϵ�ʱ��Ҳ�ǱȽ�nums[s.top()]��nums[i]����
		stack<int> s;
		vector<int> ans(nums.size(), -1);

		// ��һ�α�������һ������ջ
		for (int i = 0; i < nums.size(); i++) {
			while (!s.empty() && nums[s.top()] < nums[i]) {
				ans[s.top()] = nums[i];
				s.pop();
			}
			s.push(i);
		}

		// �ڶ��α���������Ҫ�Ե���ջ��ʣ��ĴӴ�С�������е������ɣ����ʣ�µģ�Ĭ��ֵΪ-1����������ջ�����Ч��ֵ
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
// ���������������ջ��ֵС����ջ����ջ��ֵ�󣬵���ջ�ڵ�ֵ��ֱ����ջ��ֵС����ջΪ��
// �����ǵ���ջ�������Ǳ�������
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
		//	// ���н���ģ��ٴ���ջ��Ҳ����ı�����ֱ���������� 
		//	// �ɲ�������[31,-41,59,26,-53,58,97,-93,-23,84]��֪���еĽ��ֵ�Ǹ���������-1�������������������ֻ���ٴ��ظ�
		//	if (ans[i] > -1) continue;
		//	while (!s.empty() && nums[s.top()] <= nums[i]) {
		//		s.pop();
		//	}
		//	if (!s.empty()) ans[i] = nums[s.top()];
		//	// Ҳ�����ٴ��ȥ�����ȥ���ܸı�ans�Ķ��Ѿ���������
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