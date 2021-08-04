#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;

// leetcode by Yoursong
// Runtime: 12 ms, faster than 92.61% of C++ online submissions for Max Points on a Line.
// Memory Usage : 10.9 MB, less than 51.41 % of C++ online submissions for Max Points on a Line.
class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		if (points.size() < 2) return points.size();

		int result = 0;

		// 以每一个点为起点，遍历其后与其具有同斜率的点的数目
		for (int i = 0; i < points.size(); i++) {
			// 存斜率 用pair来存，避开double unordered_map无法通过leetcode编译
			// C++ STL中的unordered_map底层是通过Hash实现的，当使用pair作为键值(Key)时，需要手动传入Hash实例类型。
			// unordered_map<pair<int, int>, int> lines;
			map<pair<int, int>, int> lines;
			int localmax = 0, overlap = 0, vertical = 0;

			// 遍历该点之后的，计算overlap，与该点重复的，如果点是排好序的，可以跳过重复点
			for (int j = i + 1; j < points.size(); j++) {
				// 与该点相同
				if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
					overlap++;
					continue;
				}
				// 在同一竖直线上 同一竖直线上可以不用单独考虑，当做斜率为{0,1}即可，只是需要同步修改求最大公约数的函数
				else if (points[j][0] == points[i][0]) vertical++;
				else {
					int a = points[j][0] - points[i][0], b = points[j][1] - points[i][1];
					int gcd = GCD(a, b);

					a /= gcd;
					b /= gcd;

					lines[make_pair(a, b)]++;
					localmax = max(lines[make_pair(a, b)], localmax);
				}

				localmax = max(vertical, localmax);
			}
			result = max(result, localmax + overlap + 1);
		}

		return result;
	}

private:
	// 求公约数 辗转相除法
	int GCD(int a, int b) {
		if (b == 0) return a;
		// 如果a<b，那么a%b=a;交换位置
		else return GCD(b, a % b);
	}
};

// 去掉同一竖直线的考虑
// Runtime: 16 ms, faster than 72.71% of C++ online submissions for Max Points on a Line.
// Memory Usage : 10.7 MB, less than 58.04 % of C++ online submissions for Max Points on a Line.

// 更改map为unorder_map后，空间占用增加
class Solution2 {
public:
	int maxPoints(vector<vector<int>>& points) {
		if (points.size() < 2) return points.size();

		int result = 0;

		// 以每一个点为起点，遍历其后与其具有同斜率的点的数目
		for (int i = 0; i < points.size(); i++) {
			// 存斜率 用pair来存，避开double unordered_map无法通过leetcode编译
			// C++ STL中的unordered_map底层是通过Hash实现的，当使用pair作为键值(Key)时，需要手动传入Hash实例类型。
			// unordered_map<pair<int, int>, int> lines;
			//map<pair<int, int>, int> lines;
			unordered_map<pair<int, int>, int,hash_pair> lines;
			int localmax = 0, overlap = 0;

			// 遍历该点之后的，计算overlap，与该点重复的，如果点是排好序的，可以跳过重复点
			for (int j = i + 1; j < points.size(); j++) {
				// 与该点相同
				if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
					overlap++;
					continue;
				}
				else {
					int a = points[j][0] - points[i][0], b = points[j][1] - points[i][1];
					int gcd = GCD(a, b);

					a /= gcd;
					b /= gcd;

					lines[make_pair(a, b)]++;
					localmax = max(lines[make_pair(a, b)], localmax);
				}
			}
			result = max(result, localmax + overlap + 1);
		}

		return result;
	}

private:
	// 求公约数 辗转相除法
	int GCD(int a, int b) {
		if (a == 0) return b;
		if (b == 0) return a;
		// 如果a<b，那么a%b=a;交换位置
		else return GCD(b, a % b);
	}

	struct hash_pair {
		template<class T1,class T2>
		size_t operator()(const pair<T1, T2>& p) const {
			auto hash1 = hash<T1>{}(p.first);
			auto hash2 = hash<T2>{}(p.second);
			return hash1 ^ hash2;
		}
	};
};

//int main(int argc, char* argv[]) {
//	vector<vector<int>> points = { {1,1},{3,2},{5,3},{4,1},{2,3},{1,4} };
//	//vector<vector<int>> points = { {0,-12},{5,2},{2,5},{0,-5},{1,5},{2,-2},{5,-4},{3,4},{-2,4},{-1,4},{0,-5},{0,-8},{-2,-1},{0,-11},{0,-9} };
//	int res = Solution().maxPoints(points);
//	return 0;
//}