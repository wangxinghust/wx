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
		// ���ұ߿�ʼ��ÿ���ͳ��ֵĴ������Ƚ�endλ�õĺ�1��ӵ�hash����
		count[0] = 1;
		int rightSum = 0;
		for (int i = A.size() - 1; i >= 1; i--) {
			rightSum += A[i];
			count[rightSum]++;
		}
		rightSum += A[0];
		int leftSum = 0, numSubarrays = 0;
		// ����߿�ʼ���ȴ�beginǰ��λ�ã�����˵-1�����λ�ã���leftSum=0ʱ�ĸ���
		if (count.find(rightSum - S) != count.end()) {
			numSubarrays += count[rightSum - S];
		}
		for (int i = 0; i < A.size(); i++) {
			leftSum += A[i];
			// ���������ͬʱ����hash�����ı������ĺ͵ļ�����ȥ
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