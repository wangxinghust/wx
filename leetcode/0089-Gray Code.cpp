#include <bitset>
#include <vector>
using namespace std;
class Solution {
	//leetcod by YuSi
	void utils(bitset<32> & bits, vector<int>& result, int k) {
		if (k == 0) {
			result.push_back(bits.to_ulong());
		}
		else {
			utils(bits, result, k - 1);
			bits.flip(k - 1);
			utils(bits, result, k - 1);
		}
	}
public:
	vector<int> grayCode(int n) {
		bitset<32> bits;
		vector<int> result;
		utils(bits, result, n);
		return result;
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	vector<int> ans;
//
//	ans = s.grayCode(3);
//	return 0;
//}