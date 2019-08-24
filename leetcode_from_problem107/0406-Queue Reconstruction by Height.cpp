#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


// 基于冒泡排序的想法，按需求往后移动，以满足(h,k)这个元素前面有k个比它大或相等的
// Runtime: 96 ms, faster than 32.62% of C++ online submissions for Queue Reconstruction by Height.
// Memory Usage : 12.1 MB, less than 100.00 % of C++ online submissions for Queue Reconstruction by Height.
class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		vector<vector<int>> ans;
		if (people.empty()) return ans;

		sort(people.begin(), people.end());

		int size = people.size();
		int num = people[0][0];
		int repeat = 0;

		vector<bool> finish(size, false);

		int start = 0;
		while (start < size) {
			int move = people[start][1] - repeat;
			if (!move) {
				finish[start] = true;
				//++start; 不能简单的+1,往后找第一个finish为false的
				while (++start < size && finish[start]);

				if (start == size) break;

				if (people[start][0] == num) {
					++repeat;
				}
				else {
					num = people[start][0];
					repeat = 0;
				}

				continue;
			}
			else {
				int i = start;
				int j = i + 1;
				while (j < size && move > 0) {
					while (finish[j]) {
						++j;
					}
					swap(people[i], people[j]);
					i = j;
					++j;
					--move;
				}
				finish[i] = true;

				if (people[start][0] == num) {
					++repeat;//start位置没变，前面存在的已重复的数的个数不会变多，bug不在这，虽然前面存在的不变，但后面存在已finish的同大小的num，repeat可以加1
				}
				else {
					num = people[start][0];
					repeat = 0;
				}
			}
		}

		return people;// 如果不允许改变people，则开辟新的内存存储并返回即可
	}
};

// leetcode by zyoppy008
// 基于插入排序
// 关键是people (h,k) 数组的排序规则，先插入 h最大，但k最小的，这样后面同样h大的，以k的位置来插入时，前面的值都是比h大或相等的
// Runtime: 80 ms, faster than 70.30% of C++ online submissions for Queue Reconstruction by Height.
// Memory Usage : 12.5 MB, less than 61.90 % of C++ online submissions for Queue Reconstruction by Height.
class Solution2 {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		auto comp = [](const vector<int>& p1, const vector<int>& p2) {
			return p1[0] > p2[0] || p1[0] == p2[0] && p1[1] < p2[1];
		};
		sort(people.begin(), people.end(), comp);
		vector<vector<int>> res;
		for (auto& p : people)
			res.insert(res.begin() + p[1], p);
		return res;
	}
};


//int main() {
//	vector<vector<int>> people = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
//	auto ans = Solution().reconstructQueue(people);
//	for (auto& n : ans) {
//		cout << n[0] << "-" << n[1] << endl;
//	}
//
//	cout << "---------" << endl;
//
//	vector<vector<int>> people2 = { {5,0},{5,2},{5,3},{6,0} };
//	auto ans2 = Solution().reconstructQueue(people2);
//	for (auto& n : ans2) {
//		cout << n[0] << "-" << n[1] << endl;
//	}
//	cout << "---------" << endl;
//	auto ans3 = Solution2().reconstructQueue(people);
//	for (auto& n : ans3) {
//		cout << n[0] << "-" << n[1] << endl;
//	}
//
//	return 0;
//}