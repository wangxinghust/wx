#include <vector>
#include <algorithm>
using namespace std;

// leetcode by songzy982
// Runtime: 8 ms, faster than 50.41% of C++ online submissions for Maximum Product Subarray.
// Memory Usage : 9.2 MB, less than 18.11 % of C++ online submissions for Maximum Product Subarray.
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int frontProduct = 1;
		int backProduct = 1;
		int ans = INT_MIN;
		for (int i = 0; i < nums.size(); ++i) {
			frontProduct *= nums[i];
			backProduct *= nums[nums.size() - i - 1];
			// 先核算ans
			ans = max(ans, max(frontProduct, backProduct));
			// 再判断frontProduct和backProduct是否遇0置1；
			frontProduct = frontProduct == 0 ? 1 : frontProduct;
			backProduct = backProduct == 0 ? 1 : backProduct;
		}
		return ans;
	}
};

//int main(int argc, char* argv[]) {
//	//vector<int> nums = { 2,3,-2,4 };
//	vector<int> nums = { -2,0,-1 };
//	int product = Solution().maxProduct(nums);
//	return 0;
//}