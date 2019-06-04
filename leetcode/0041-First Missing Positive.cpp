#include <vector>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i)
			//ѭ��������ʹnums[i]-1λ�ô���ֵ�뵱ǰλ�õ�ֵ�����
			while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i] - 1]);

		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				return i + 1;
		return nums.size() + 1;
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> nums = { 2,2,4,1,3 };
//	Solution s;
//	int i = s.firstMissingPositive(nums);
//	return 0;
//}