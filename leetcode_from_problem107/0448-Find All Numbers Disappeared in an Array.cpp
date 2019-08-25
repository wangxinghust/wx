#include <vector>
using namespace std;

// ������hash�������е����ƾ�̬����
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			// ���ÿ���Խ�磬��Ŀ�������������������ݵĴ�С
			while (nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != i + 1) result.push_back(i + 1);
		}
		return result;
	}
};