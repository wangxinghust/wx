#include <vector>
using namespace std;
class Solution {
public:

	//��0026�Ļ����ϸĽ�������һ��boolֵ�����жϼ��ɣ��������κ�boolֵ��false���µĲ�ͬ��ֵʱ��boolֵ��true
	//������two pointer�ⷨ
	//Runtime: 12 ms, faster than 94.73% of C++ online submissions for Remove Duplicates from Sorted Array II.
	//Memory Usage : 8.9 MB, less than 47.54 % of C++ online submissions for Remove Duplicates from Sorted Array II.
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int i = 0;
		bool once = true;
		for (int j = 1; j < nums.size(); ++j) {
			if (nums[j] != nums[i]) {
				++i;
				nums[i] = nums[j];
				once = true;
			}
			else if (nums[j] == nums[i] && once) {
				++i;
				nums[i] = nums[j];
				once = false;
			}
		}
		return i + 1;
	}
};