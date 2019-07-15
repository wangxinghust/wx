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

		// 相当于一个映射，mid递增，相当于1,3,5,7,0,2,4,6序列里往后遍历
		auto m = [n](int idx) { return (2 * idx + 1) % (n | 1); };
		int first = 0, mid = 0, last = n - 1;
		// 举例:
		// 原数组:	a b c d e f
		// 下标:		0 1 2 3 4 5
		// m():		1 3 5 0 2 4
		// 新数组:	b d f a c e
		// 由于前面的nth_element，原数组是排好序的，以上仅为举例，辅助理解,经过以上坐标变换，将奇数偶数划分开了，从前遍历是奇数，从后遍历是偶数
		// 以0为起始，0为偶数位，因此，较小的数放偶数位，较大的数放奇数位
		// 经过遍历交换后，前面的奇数位是大于median的，后面的偶数位是小于median的，这样，median在后面的奇数位，和前面的偶数位，满足求解条件
		while (mid <= last) {
			// 将大于median的放于靠前的奇数位
			if (nums[m(mid)] > median) {
				swap(nums[m(first)], nums[m(mid)]);
				++first;
				++mid;
			}
			// 将小于median的放于靠后的偶数位
			else if (nums[m(mid)] < median) {
				swap(nums[m(mid)], nums[m(last)]);
				--last;
			}
			// 相等的放入其他槽位，也就是无需处理，自动交换到位置
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