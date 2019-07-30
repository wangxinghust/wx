#include <vector>
#include <unordered_map>
using namespace std;

// Runtime: 52 ms, faster than 50.84% of C++ online submissions for Binary Subarrays With Sum.
// Memory Usage : 17 MB, less than 52.46 % of C++ online submissions for Binary Subarrays With Sum.
class Solution {
public:
	int numSubarraysWithSum(vector<int>& A, int S) {
		if (A.empty()) return 0;
		unordered_map<int, int> count;		
		//count.insert(make_pair(0, 1));
		// 从右边开始求每个和出现的次数，先将end位置的和1添加到hash表里
		count[0] = 1;
		int rightSum = 0;
		for (int i = A.size() - 1; i >= 1; i--) {
			rightSum += A[i];
			count[rightSum]++;
		}
		rightSum += A[0];
		int leftSum = 0, numSubarrays = 0;
		// 从左边开始，先从begin前的位置，或者说-1代表的位置，求leftSum=0时的个数
		if (count.find(rightSum - S) != count.end()) {
			numSubarrays += count[rightSum - S];
		}
		for (int i = 0; i < A.size(); i++) {
			leftSum += A[i];
			// 遍历计算的同时，将hash表里存的遍历过的和的计数减去
			count[rightSum - leftSum]--;
			if (count.find(rightSum - leftSum - S) != count.end()) {
				numSubarrays += count[rightSum - leftSum - S];
			}
		}
		return numSubarrays;
	}
};

//int main(int argc, char* argv[]) {
//	//vector<int> A = { 1,0,1,0,1 };
//	//vector<int> A = { 0,0,0,0,0 };
//	vector<int> A = { 0,0,0,0,0,0,1,0,0,0 };
//	int num = Solution().numSubarraysWithSum(A, 0);
//	return 0;
//}