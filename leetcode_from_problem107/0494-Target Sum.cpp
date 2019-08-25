#include <iostream>
#include <vector>
#include <thread>
using namespace std;

// �ݹ�д�� ��δ����S=INT_MAX��������� wrong answer
class Solution {
	int recurse(vector<int>& nums, int sum, int start) {
		if (start == nums.size() - 1) {
			if (sum == nums[start] || sum == -nums[start]) {
				return 1;
			}
			else
				return 0;
		}
		return recurse(nums, sum + nums[start], start + 1) + recurse(nums, sum - nums[start], start + 1);
	}
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		return recurse(nums, S, 0);
	}
};

// Approach #1 Brute Force[Accepted]
// ͨ������жϺ��Ƿ�ΪS���ܿ��˶�S�ļӼ����Ӷ��ܿ����
class Solution2 {
	int count = 0;
	void calculate(vector<int>& nums, int i, int sum, int& S) {
		if (i == nums.size()) {
			if (sum == S)
				count++;
		}
		else {
			calculate(nums, i + 1, sum + nums[i], S);
			calculate(nums, i + 1, sum - nums[i], S);
		}
	}
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		calculate(nums, 0, 0, S);
		return count;
	}
};

// Approach #2 Recursion with memoization [Accepted]
// ȫȡ������СΪ-1000����ƫ����1000���渺�ĺ�
class Solution3 {
	int calculate(vector<int>& nums, int i, int sum, int& S,vector<vector<int>> memo) {
		//cout << nums.size() << "-" << i << "-" << sum << endl;

		if (i == nums.size()) {
			cout << "������ֹ����\n";
			this_thread::sleep_for(chrono::seconds(1));
			if (sum == S)
				return 1;
			else
				return 0;
		}
		else {
			if (memo[i][sum + 1000] != INT_MIN) {
				return memo[i][sum + 1000];
			}
			int add = calculate(nums, i + 1, sum + nums[i], S, memo);
			int subtract = calculate(nums, i + 1, sum - nums[i], S, memo);
			memo[i][sum + 1000] = add + subtract;
			cout << "�˳�����\n";
			this_thread::sleep_for(chrono::seconds(1));
			return memo[i][sum + 1000];
		}
	}
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		vector<vector<int>> memo(nums.size(), vector<int>(2001, INT_MIN));
		return calculate(nums, 0, 0, S, memo);
	}
};

//int main() {
//	vector<int> nums = { 2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53 };
//	int ans = Solution3().findTargetSumWays(nums, INT_MAX);
//	return 0;
//}