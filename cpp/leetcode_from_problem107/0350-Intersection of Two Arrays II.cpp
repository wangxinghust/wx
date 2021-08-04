#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		int index1 = 0, index2 = 0;
		vector<int> ret;
		while (index1 < nums1.size() && index2 < nums2.size()) {
			if (nums1[index1] < nums2[index2])
				++index1;
			else if (nums1[index1] > nums2[index2])
				++index2;
			else {
				ret.push_back(nums1[index1]);
				++index1;
				++index2;
			}
		}

		return ret;
	}
};