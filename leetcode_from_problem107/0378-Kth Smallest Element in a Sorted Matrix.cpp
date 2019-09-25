#include <vector>
#include <queue>
using namespace std;

// Runtime: 56 ms, faster than 48.94% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
// Memory Usage : 12 MB, less than 63.89 % of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		auto cmp = [](pair<int, int> a, pair<int, int> b) {return a.first > b.first; };
		priority_queue < pair<int, int>, vector<pair<int, int>>, decltype(cmp)  > nums(cmp);
		for (int i = 0; i < matrix.size(); ++i) {
			nums.push(make_pair(matrix[i][0], i));
		}
		int flag = 0;
		vector<int> index(matrix.size(), 1);
		while (flag < k - 1) {
			int i = nums.top().second;
			nums.pop();
			if (index[i] < matrix[i].size())
				nums.push(make_pair(matrix[i][index[i]++], i));
			++flag;
		}
		return nums.top().first;
	}
};

// leetcode by 2997ms: binary search
// Runtime: 36 ms, faster than 95.36% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
// Memory Usage : 11.9 MB, less than 91.29 % of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
class Solution2 {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int le = matrix[0][0], ri = matrix[n - 1][n - 1];
		int mid = 0;
		while (le < ri)
		{
			// 计算中值
			mid = le + (ri - le) / 2;
			// 检查mid对应的num与k值的关系
			int num = 0;
			for (int i = 0; i < n; i++)
			{
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				num += pos;
			}
			// 少于k，说明需要增大mid值，即移动le值
			if (num < k)
			{
				le = mid + 1;
			}
			else
			{
				ri = mid;
			}
		}
		return le;
	}
};

//int main(int argc, char* argv[]) {
//	vector<vector<int>> matrix = { {1,5,9},{10,11,13},{12,13,15} };
//	int ret = Solution().kthSmallest(matrix, 8);
//	return 0;
//}