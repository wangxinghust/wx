#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Largest Number.
// Memory Usage : 9.2 MB, less than 40.57 % of C++ online submissions for Largest Number.
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector<string> strs;
		for (int i = 0; i < nums.size(); i++) {
			strs.push_back(to_string(nums[i]));
		}
		sort(strs.begin(), strs.end(), compare);

		// ÅÅ³ýÈ«0×´¿ö
		if (strs[0] == "0") return "0";

		string res = "";
		for (int i = 0; i < strs.size(); i++) {
			res += strs[i];
		}
		return res;
	}
	static bool compare(string a, string b) {
		return a + b > b + a;
	}
};

//int main(int argc, char* argv[]) {
//	//vector<int> nums = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
//	//vector<int> nums = { 824,938,1399,5607,6973,5703,9609,4398,8247 };
//	vector<int> nums = { 121,12 };
//	string res = Solution().largestNumber(nums);
//	return 0;
//}