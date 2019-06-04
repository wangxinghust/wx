#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) return;
		//��ĩβ�����ڶ�����ʼѭ��
		for (int i = nums.size() - 2; i >= 0; --i) {
			//���ڱȽϣ�ֱ���ҵ���һ�������С��
			if (nums[i] < nums[i + 1]) {
				//��������Ժ��ҳ����������������������С�ģ����������
				swap(nums[i], nums[minIndex(nums, i + 1, nums[i])]);
				//���������������õ���С����
				sort(nums.begin() + i + 1, nums.end());
				return;
			}
		}
		//���һ����Ҳ�Ҳ�����������Ϊ���򣬰���ĿҪ��ת���ɣ���sortһ��Ҳ��
		reverse(nums.begin(), nums.end());
	}
	int minIndex(vector<int>& nums, int i, int numBase) {
		int minIndex = i;
		++i;
		for (; i < nums.size(); ++i) {
			if (nums[i] > numBase && nums[i] < nums[minIndex]) minIndex = i;
		}
		return minIndex;
	}
};


//int main(int argc, char* argv[]) {
//	vector<int> nums = { 2,3,1 };
//	Solution s;
//	s.nextPermutation(nums);
//	for (int i : nums) {
//		cout << i << endl;
//	}
//	return 0;
//}