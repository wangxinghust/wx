#include <vector>
using namespace std;

// Approach 1: Brute Force[Time Limit Exceeded]

// Approach 2: Using Extra Array
// Runtime: 16 ms, faster than 90.46% of C++ online submissions for Rotate Array.
// Memory Usage : 9.4 MB, less than 83.95 % of C++ online submissions for Rotate Array.
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		// extra array
		vector<int> a(nums.size());
		// copy nums[i] to a[(i+k)%nums.size()]
		for (int i = 0; i < nums.size(); i++) {
			a[(i + k) % nums.size()] = nums[i];
		}
		// copy a to nums
		for (int i = 0; i < nums.size(); i++) {
			nums[i] = a[i];
		}
	}
};

// Approach 3: Using Cyclic Replacements
// Runtime: 16 ms, faster than 90.46% of C++ online submissions for Rotate Array.
// Memory Usage : 9.5 MB, less than 49.68 % of C++ online submissions for Rotate Array.
class Solution2 {
public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		int count = 0;
		for (int start = 0; count < nums.size(); start++) {
			int current = start;
			int prev = nums[start];
			do {
				int next = (current + k) % nums.size();
				int temp = nums[next];
				nums[next] = prev;
				prev = temp;
				current = next;
				count++;
			} while (start != current);
		}
	}
};

// take out the count
// 循环内已经遍历所有元素了，当k==nums.size()时，不执行循环
// Wrong Answer: 无法通过测试用例[1,2,3,4,5,6] 2; 第一次进入循环后，回到了start点，未遍历完即退出了循环
class Solution3 {
public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		int current = 0;
		int prev = nums[0];
		do {
			int next = (current + k) % nums.size();
			int temp = nums[next];
			nums[next] = prev;
			prev = temp;
			current = next;
		} while (current);
	}
};

// Approach 4: Using Reverse
// Runtime: 12 ms, faster than 99.63% of C++ online submissions for Rotate Array.
// Memory Usage : 9.4 MB, less than 92.51 % of C++ online submissions for Rotate Array.
class Solution4 {
public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> nums = { 1,2,3,4,5,6,7 };
//	Solution4().rotate(nums, 3);
//	return 0;
//}