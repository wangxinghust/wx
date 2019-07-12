#include <vector>
using namespace std;

// Runtime: 36 ms, faster than 98.12% of C++ online submissions for Product of Array Except Self.
// Memory Usage : 12.6 MB, less than 42.60 % of C++ online submissions for Product of Array Except Self.
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> product(nums.size(), 1);
		for (int i = 1; i < nums.size(); ++i) {
			product[i] = product[i - 1] * nums[i - 1];
		}
		int rightProduct = nums[nums.size() - 1];
		for (int i = nums.size() - 2; i >= 0; --i) {
			product[i] *= rightProduct;
			rightProduct *= nums[i];
		}
		return product;
	}
};