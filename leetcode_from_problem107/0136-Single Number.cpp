#include <vector>
#include <set>
#include <list>
using namespace std;

// ����ĿҪ��ֻ����λ��������

// leetcode Approach 1: List operation
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		list<int> no_duplicate_list;
		for (int i : nums) {
			auto pos = find(no_duplicate_list.begin(), no_duplicate_list.end(), i);
			if (pos != no_duplicate_list.end()) no_duplicate_list.erase(pos);
			else no_duplicate_list.insert(pos, i);
		}
		return *(no_duplicate_list.begin());
	}
};

// leetcode Approach 2: Hash Table
class Solution2 {

};