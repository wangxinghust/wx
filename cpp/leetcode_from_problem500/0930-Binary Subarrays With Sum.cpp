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

// Approach 1: Index of Ones
// Runtime: 32 ms, faster than 66.10% of C++ online submissions for Binary Subarrays With Sum.
// Memory Usage : 11.5 MB, less than 72.00 % of C++ online submissions for Binary Subarrays With Sum.
class Solution2 {
public:
	int numSubarraysWithSum(vector<int>& A, int S) {
		int su = 0;
		for (int x : A) su += x;

		// index[i] = location of i-th one (1 indexed)
		vector<int> indexes(su + 2);
		int t = 0;
		indexes[t++] = -1;
		for (int i = 0; i < A.size(); ++i) {
			if (A[i] == 1) {
				indexes[t++] = i;
			}
		}
		indexes[t] = A.size();

		int ans = 0;

		// special circumstances
		if (S == 0) {
			for (int i = 0; i < indexes.size() - 1; ++i) {
				// w: number of zeros between consecutive ones
				int w = indexes[i + 1] - indexes[i] - 1;
				ans += w * (w + 1) / 2;
			}
			return ans;
		}

		for (int i = 1; i < indexes.size() - S; ++i) {
			int j = i + S - 1;
			int left = indexes[i] - indexes[i - 1];
			int right = indexes[j + 1] - indexes[j];
			ans += left * right;
		}

		return ans;
	}
};

// Approach 2: Prefix Sums
// Runtime: 56 ms, faster than 40.34% of C++ online submissions for Binary Subarrays With Sum.
// Memory Usage : 19.8 MB, less than 14.00 % of C++ online submissions for Binary Subarrays With Sum.
class Solution3 {
public:
	int numSubarraysWithSum(vector<int>& A, int S) {
		int N = A.size();
		vector<int> P(N + 1);
		for (int i = 0; i < N; i++) {
			P[i + 1] = P[i] + A[i];
		}

		unordered_map<int, int> count;
		int ans = 0;
		// 对每一个prifix sum, 找之前x-S被计数了几次，也相当于，遍历到j的时候，找j之前，能凑出S的个数
		for (int x : P) {
			ans += count[x];
			count[x + S] += 1;
		}
		return ans;
	}
};

// Approach 3: Three Pointer
// 类似滑动窗口
// Runtime: 24 ms, faster than 95.25% of C++ online submissions for Binary Subarrays With Sum.
// Memory Usage : 10.9 MB, less than 100.00 % of C++ online submissions for Binary Subarrays With Sum.
class Solution4 {
public:
	int numSubarraysWithSum(vector<int>& A, int S) {
		int iLo = 0, iHi = 0;
		int sumLo = 0, sumHi = 0;
		int ans = 0;
		
		for (int j = 0; j < A.size(); ++j) {
			// while sumLo is too big, iLo++
			sumLo += A[j];
			while (iLo<j && sumLo>S) {
				sumLo -= A[iLo++];
			}
			// while sumHi is too big, or equal and we can move, iHi++
			sumHi += A[j];
			while (iHi < j && (sumHi > S || sumHi == S && A[iHi] == 0)) {
				sumHi -= A[iHi++];
			}
			if (sumLo == S) {
				ans += iHi - iLo + 1;
			}
		}

		return ans;
	}
};

//int main(int argc, char* argv[]) {
//	//vector<int> A = { 1,0,1,0,1 };
//	//vector<int> A = { 0,0,0,0,0 };
//	vector<int> A = { 0,0,0,0,0,0,1,0,0,0 };
//	int num = Solution3().numSubarraysWithSum(A, 0);
//	return 0;
//}