#include <vector>
using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0) return 0;
		vector<int>::iterator it = nums.begin();
		while (it != nums.end()) {
			if (*it == val) {
				it = nums.erase(it);
			}
			else {
				++it;
			}
		}
		return nums.size();
	}
};