#include <vector>
#include <algorithm>
using namespace std;
// ˫ָ��
// Runtime: 8 ms, faster than 97.79% of C++ online submissions for Minimum Size Subarray Sum.
// Memory Usage : 10 MB, less than 45.38 % of C++ online submissions for Minimum Size Subarray Sum.
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		// ���Ϊnums.size()+1, ���ڱܿ������С��s�����,�޷��������鳤��ΪINT_MAX�����
		int minLen = nums.size() + 1;
		int sum = 0;
		int right = 0;
		for (int i = 0; i < nums.size(); ++i) {
			while (right < nums.size() && sum < s) {
				sum += nums[right];
				right++;
			}
			if (sum >= s) {
				minLen = min(minLen, right - i);
				sum -= nums[i];
			}
		}
		// �ж�������Ƿ�С��s����minLen�Ƿ�ı��
		return minLen == nums.size() + 1 ? 0 : minLen;
	}
};

// leetcode��ͬ˼·�ⷨ
// Runtime: 12 ms, faster than 78.43% of C++ online submissions for Minimum Size Subarray Sum.
// Memory Usage : 9.9 MB, less than 60.54 % of C++ online submissions for Minimum Size Subarray Sum.
class Solution2 {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		int ans = INT_MAX;
		int left = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			while (sum >= s) {
				ans = min(ans, i + 1 - left);
				sum -= nums[left++];
			}
		}
		return (ans != INT_MAX) ? ans : 0;
	}
};