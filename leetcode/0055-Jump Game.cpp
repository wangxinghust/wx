#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	//����0045�⣬̰���㷨�Ľ�
	//Runtime: 8 ms
	//Memory Usage : 10.1 MB
	bool canJump1(vector<int>& nums) {
		int curEnd = 0, curFarthest = 0;
		for (int i = 0; i < nums.size(); ++i) {//������0045��һ������Ҫ���������һ���㣬����{3,2,1,0,1}���������ӻ��޷�ͨ����������ɣ��պ�ͣ�ڵ����ڶ�����
			curFarthest = max(curFarthest, i + nums[i]);
			if (i == curEnd) {
				curEnd = curFarthest;
				//continue;//����continue�� Runtime��8ms�䵽��12ms
			}
			if (i > curEnd) {//��������˵����ܷ��ʵĵ㣬�򷵻�false�����������i<=curEnd; ��������»����curEnd��ֻ�������ϵ㣬curEnd���º�Ҳ��ԭֵ
				return false;
			}
		}
		return true;
	}


	//Approach 1: Backtracking
	bool canJump2(vector<int>& nums) {
		return canJumpFromPosition2(0, nums);
	}
	bool canJumpFromPosition2(int position, vector<int>& nums) {
		if (position == nums.size() - 1) {
			return true;
		}
		int furthestJump = min(position + nums[position], int(nums.size() - 1));
		//for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) { �Ż�ǰ���ı����˳��
		for (int nextPosition = furthestJump; nextPosition > position; nextPosition--) {
			if (canJumpFromPosition2(nextPosition, nums)) {
				return true;
			}
		}
		return false;
	}

	//Approach 2: Dynamic Programming Top-down
	enum Index {
		GOOD, BAD, UNKNOWN
	};

	bool canJumpFromPosition3(int position, vector<int>& nums, vector<Index>& memo) {
		if (memo[position] != UNKNOWN) {
			return memo[position] == GOOD ? true : false;
		}
		int furthestJump = min(position + nums[position], int(nums.size() - 1));
		for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
			if (canJumpFromPosition3(nextPosition, nums, memo)) {
				memo[position] = GOOD;
				return true;
			}
		}

		memo[position] = BAD;
		return false;
	}

	bool canJump3(vector<int>& nums) {
		vector<Index> memo(nums.size());
		for (int i = 0; i < memo.size() - 1; i++) {
			memo[i] = UNKNOWN;
		}
		memo[memo.size() - 1] = GOOD;
		return canJumpFromPosition3(0, nums, memo);
	}

	//Approach 3: Dynamic Programming Bottom-up
	bool canJump4(vector<int>& nums) {
		vector<Index> memo(nums.size());
		for (int i = 0; i < memo.size() - 1; i++) {
			memo[i] = UNKNOWN;
		}
		memo[memo.size() - 1] = GOOD;

		for (int i = nums.size() - 2; i >= 0; i--) {
			int furthestJump = min(i + nums[i], int(nums.size() - 1));
			for (int j = i + 1; j <= furthestJump; j++) {
				if (memo[j] == GOOD) {
					memo[i] = GOOD;
					break;
				}
			}
		}
		return memo[0] == GOOD;
	}

	//Approach 4: Greedy
	//Runtime: 12 ms, faster than 92.36% of C++ online submissions for Jump Game.
	//Memory Usage : 10.1 MB, less than 56.01 % of C++ online submissions for Jump Game.
	bool canJump(vector<int>& nums) {
		int lastPos = nums.size() - 1;
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (i + nums[i] >= lastPos) {//���������ܵ���lastPos������������ΪlastPos
				lastPos = i;
			}
		}
		return lastPos == 0;
	}

};

//int main(int argc, char* argv[]) {
//	vector<int> nums = { 3,2,1,0,1,4 };
//	Solution s;
//	bool b = s.canJump(nums);
//	return 0;
//}