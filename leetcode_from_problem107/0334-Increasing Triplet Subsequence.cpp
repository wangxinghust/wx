#include <vector>
using namespace std;

// 0300-Longest Increasing Subsequence�ļ򻯰�
// 3������sub���飬����nums���飬������ģ�׷�ӣ�����С�ģ����º���λ�õ�ֵ
class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		if (nums.size() < 3) return false;
		int len = 0;
		int sub[3];
		sub[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			// �������ĩβֵ����׷��
			if (nums[i] > sub[len]) {
				sub[++len] = nums[i];
			}
			else {
				// lenΪ0��1
				if (len) { // lenΪ1
					// С�ڵ��ڵ�һ����
					if (nums[i] <= sub[len - 1])
						sub[len - 1] = nums[i];
					// ���ڵ�һ�������ֲ����ڵڶ����������뵽�ڶ�������λ��
					else
						sub[len] = nums[i];
				}
				else // lenΪ0
					// ��ȻС�ڵ���sub[0]������sub[len]Ҳ����sub[0]����
					sub[len] = nums[i];
			}
			if (len == 2) 
				return true;
		}
		return false;
	}
};