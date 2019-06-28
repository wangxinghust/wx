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

		// ��ÿһ����Ϊ��㣬��������������ͬб�ʵĵ����Ŀ
		for (int i = 0; i < points.size(); i++) {
			// ��б�� ��pair���棬�ܿ�double unordered_map�޷�ͨ��leetcode����
			// C++ STL�е�unordered_map�ײ���ͨ��Hashʵ�ֵģ���ʹ��pair��Ϊ��ֵ(Key)ʱ����Ҫ�ֶ�����Hashʵ�����͡�
			// unordered_map<pair<int, int>, int> lines;
			map<pair<int, int>, int> lines;
			int localmax = 0, overlap = 0, vertical = 0;

			// �����õ�֮��ģ�����overlap����õ��ظ��ģ���������ź���ģ����������ظ���
			for (int j = i + 1; j < points.size(); j++) {
				// ��õ���ͬ
				if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
					overlap++;
					continue;
				}
				// ��ͬһ��ֱ���� ͬһ��ֱ���Ͽ��Բ��õ������ǣ�����б��Ϊ{0,1}���ɣ�ֻ����Ҫͬ���޸������Լ���ĺ���
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
	// ��Լ�� շת�����
	int GCD(int a, int b) {
		if (b == 0) return a;
		// ���a<b����ôa%b=a;����λ��
		else return GCD(b, a % b);
	}
};

// ȥ��ͬһ��ֱ�ߵĿ���
// Runtime: 16 ms, faster than 72.71% of C++ online submissions for Max Points on a Line.
// Memory Usage : 10.7 MB, less than 58.04 % of C++ online submissions for Max Points on a Line.

// ����mapΪunorder_map�󣬿ռ�ռ������
class Solution2 {
public:
	int maxPoints(vector<vector<int>>& points) {
		if (points.size() < 2) return points.size();

		int result = 0;

		// ��ÿһ����Ϊ��㣬��������������ͬб�ʵĵ����Ŀ
		for (int i = 0; i < points.size(); i++) {
			// ��б�� ��pair���棬�ܿ�double unordered_map�޷�ͨ��leetcode����
			// C++ STL�е�unordered_map�ײ���ͨ��Hashʵ�ֵģ���ʹ��pair��Ϊ��ֵ(Key)ʱ����Ҫ�ֶ�����Hashʵ�����͡�
			// unordered_map<pair<int, int>, int> lines;
			//map<pair<int, int>, int> lines;
			unordered_map<pair<int, int>, int,hash_pair> lines;
			int localmax = 0, overlap = 0;

			// �����õ�֮��ģ�����overlap����õ��ظ��ģ���������ź���ģ����������ظ���
			for (int j = i + 1; j < points.size(); j++) {
				// ��õ���ͬ
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
	// ��Լ�� շת�����
	int GCD(int a, int b) {
		if (a == 0) return b;
		if (b == 0) return a;
		// ���a<b����ôa%b=a;����λ��
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