#include <vector>
using namespace std;

// ����Ļ���ʱ�临�ӶȲ�����Ҫ��
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		// ����hash������뷨������Ӧ��ֵ�洢����Ӧ������
		for (int i = 0; i < nums.size(); ++i)
			//ѭ��������ʹnums[i]-1λ�ô���ֵ�뵱ǰλ�õ�ֵ�����
			while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i] - 1]);

		// ������ֵ
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				return i + 1;
		return nums.size() + 1;
	}
};

// 2019��8��18��19:26:32 ͷ��һ������
// ����ʱ����˼·����vector<bool>���棬����ͬ����С�����飬ͬʱ����һ��flag��ǣ���ʼֵ��Ϊ1
// һ�߱����������飬һ���޸�vector<bool>������Ӧλ�õ�ֵ��ͬʱflag��������bool�����������������û������

//int main(int argc, char* argv[]) {
//	// vector<int> nums = { 2,2,4,1,3 };
//	vector<int> nums = { 3,4,-1,1 };
//	Solution s;
//	int i = s.firstMissingPositive(nums);
//	return 0;
//}