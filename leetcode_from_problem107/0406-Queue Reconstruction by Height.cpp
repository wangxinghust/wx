#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


// ����ð��������뷨�������������ƶ���������(h,k)���Ԫ��ǰ����k�����������ȵ�
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
				//++start; ���ܼ򵥵�+1,�����ҵ�һ��finishΪfalse��
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
					++repeat;//startλ��û�䣬ǰ����ڵ����ظ������ĸ��������࣬bug�����⣬��Ȼǰ����ڵĲ��䣬�����������finish��ͬ��С��num��repeat���Լ�1
				}
				else {
					num = people[start][0];
					repeat = 0;
				}
			}
		}

		return people;// ���������ı�people���򿪱��µ��ڴ�洢�����ؼ���
	}
};

// leetcode by zyoppy008
// ���ڲ�������
// �ؼ���people (h,k) �������������Ȳ��� h��󣬵�k��С�ģ���������ͬ��h��ģ���k��λ��������ʱ��ǰ���ֵ���Ǳ�h�����ȵ�
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