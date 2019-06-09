#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	//Runtime: 4 ms, faster than 90.12% of C++ online submissions for Sort Colors.
	//Memory Usage : 8.6 MB, less than 33.88 % of C++ online submissions for Sort Colors.
	void sortColors(vector<int>& nums) {
		int left = 0, right = nums.size() - 1, i = 0;
		while (i <= right) {
			switch (nums[i]) {
			case 0:
				//��ǰ������ǰ���������ֻ����0��1
				swap(nums[left], nums[i]);
				left++;
				i++;
				break;
			case 2:
				//��󽻻�����������ֵ��ȷ��
				swap(nums[right], nums[i]);
				right--;
				break;
			case 1:
				i++;
				break;
			}
		}
	}

	//�Ľ� ���ж�2���Ϳ��Ա�֤��������ֻʣ0��1�� leetcode by yidawang
	//Runtime: 4 ms, faster than 90.12% of C++ online submissions for Sort Colors.
	//Memory Usage : 8.7 MB, less than 13.05 % of C++ online submissions for Sort Colors.
	void sortColors2(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		for (int i = 0; i <= right; i++) {
			//while���i<right��i>left�жϲ�����
			while (nums[i] == 2 && i < right) swap(nums[i], nums[right--]);
			while (nums[i] == 0 && i > left) swap(nums[i], nums[left++]);
		}
	}

	//�ڷ���1�Ļ����ϸĽ��﷨�����ܷ񽵵Ϳռ�ռ�� ��������swap()
	//Runtime: 4 ms, faster than 90.12% of C++ online submissions for Sort Colors.
	//Memory Usage : 8.8 MB, less than 5.18 % of C++ online submissions for Sort Colors.
	void sortColors3(vector<int>& nums) {
		int left = 0, right = nums.size() - 1, i = 0;
		while (i <= right) {
			switch (nums[i]) {
			case 0:
				nums[i] = nums[left];
				nums[left++] = 0;
				i++;
				break;
			case 2:
				nums[i] = nums[right];
				nums[right--] = 2;
				break;
			case 1:
				i++;
				break;
			}
		}
	}

	//leetcode by autekroy
	//Runtime: 8 ms, faster than 20.15% of C++ online submissions for Sort Colors.
	//Memory Usage : 8.8 MB, less than 5.18 % of C++ online submissions for Sort Colors.
	void sortColors4(vector<int>& nums) {
		int red = -1, white = -1, blue = -1;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				nums[++blue] = 2;
				nums[++white] = 1;
				nums[++red] = 0;
			}
			else if (nums[i] == 1) {
				nums[++blue] = 2;
				nums[++white] = 1;
			}
			else if (nums[i] == 2)
				nums[++blue] = 2;
		}
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> nums = { 1,2,0 };
//	Solution s;
//	s.sortColors4(nums);
//	return 0;
//}