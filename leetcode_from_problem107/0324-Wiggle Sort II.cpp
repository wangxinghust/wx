#include <vector>
#include <algorithm>
using namespace std;

// leetcode by zhiqing_xiao
// https://leetcode.com/problems/wiggle-sort-ii/discuss/77681/O(n)-time-O(1)-space-solution-with-detail-explanations
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		if (nums.empty()) {
			return;
		}
		int n = nums.size();

		// Step 1: Find the median    		
		vector<int>::iterator nth = next(nums.begin(), n / 2);
		nth_element(nums.begin(), nth, nums.end());
		int median = *nth;

		// Step 2: Tripartie partition within O(n)-time & O(1)-space. 

		// �൱��һ��ӳ�䣬mid�������൱��1,3,5,7,0,2,4,6�������������
		auto m = [n](int idx) { return (2 * idx + 1) % (n | 1); };
		int first = 0, mid = 0, last = n - 1;
		// ����:
		// ԭ����:	a b c d e f
		// �±�:		0 1 2 3 4 5
		// m():		1 3 5 0 2 4
		// ������:	b d f a c e
		// ����ǰ���nth_element��ԭ�������ź���ģ����Ͻ�Ϊ�������������,������������任��������ż�����ֿ��ˣ���ǰ�������������Ӻ������ż��
		// ��0Ϊ��ʼ��0Ϊż��λ����ˣ���С������ż��λ���ϴ����������λ
		// ��������������ǰ�������λ�Ǵ���median�ģ������ż��λ��С��median�ģ�������median�ں��������λ����ǰ���ż��λ�������������
		while (mid <= last) {
			// ������median�ķ��ڿ�ǰ������λ
			if (nums[m(mid)] > median) {
				swap(nums[m(first)], nums[m(mid)]);
				++first;
				++mid;
			}
			// ��С��median�ķ��ڿ����ż��λ
			else if (nums[m(mid)] < median) {
				swap(nums[m(mid)], nums[m(last)]);
				--last;
			}
			// ��ȵķ���������λ��Ҳ�������账���Զ�������λ��
			else {
				++mid;
			}
		}
	}
};

//int main(int argc, char* argv[]) {
//	//vector<int> nums = { 1,1,2,2,3,3 };
//	vector<int> nums = { 1,5,1,1,6,4 };
//	Solution().wiggleSort(nums);
//	return 0;
//}