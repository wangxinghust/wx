#include <algorithm>
#include <vector>
using namespace std;

// �����ֽ�2019У�� ��3

// Approach 1: Brute Force
// ȫ��1������ѭ����ֱ��flag��־Ϊfalse
// Time Limit Exceeded
class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<int> candies(ratings.size());
		fill(candies.begin(), candies.end(), 1);
		bool flag = true;
		while (flag) {
			flag = false;
			for (int i = 0; i < ratings.size(); i++) {
				if (i != ratings.size() - 1 && ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
					candies[i] = candies[i + 1] + 1;
					flag = true;
				}
				if (i > 0 && ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
					candies[i] = candies[i - 1] + 1;
					flag = true;
				}
			}
		}
		int sum = 0;
		for (int candy : candies) {
			sum += candy;
		}
		return sum;
	}
};

// Approach 2: Using two arrays
// ���Ƶ�ʱ�Լ����뷨��������Ҫ����������,����������ϴ�ֵ�ϲ�
class Solution2 {
public:
	int candy(vector<int>& ratings) {
		vector<int> left2right(ratings.size(), 1);
		vector<int> right2left(ratings.size(), 1);
		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1]) {
				left2right[i] = left2right[i - 1] + 1;
			}
		}
		for (int i = ratings.size() - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1]) {
				right2left[i] = right2left[i + 1] + 1;
			}
		}
		int sum = 0;
		for (int i = 0; i < ratings.size(); i++) {
			sum += max(left2right[i], right2left[i]);
		}
		return sum;
	}
};

// Approach 3: Using one array
// ���ԸĽ��� one array,�ڶ��α���ʱ��max������ֵ����

// Approach 4: Single Pass Approach with Constant Space
class Solution4 {
public:
	int count(int n) {
		return n * (n + 1) / 2;
	}
	int candy(vector<int>& ratings) {
		if (ratings.size() <= 1)
			return ratings.size();
		int candies = 0;
		int up = 0;
		int down = 0;
		int old_slope = 0;
		for (int i = 1; i < ratings.size(); i++) {
			int new_slope = (ratings[i] > ratings[i - 1]) ? 1 : (ratings[i] < ratings[i - 1] ? -1 : 0);
			// ����ɽ����ò
			if (old_slope > 0 && new_slope == 0 || old_slope < 0 && new_slope >= 0) {
				candies += count(up) + count(down) + max(up, down); // ��ʱ�����µĹȵ׵�1
				up = 0;
				down = 0;
			}
			if (new_slope > 0) {
				up++;
			}
			if (new_slope < 0) {
				down++;
			}
			// ���б��Ϊ0������ǰ��ȵ׵�1����
			if (new_slope == 0) {
				candies++;
			}
			old_slope = new_slope;
		}
		candies += count(up) + count(down) + max(up, down) + 1;
		return candies;
	}
};

//int main() {
//	vector<int> ratings = { 1,2,3,4,5,3,2,1,2,6,5,4,3,3,2,1,1,3,3,3,4,2 };
//	int candies = Solution4().candy(ratings);
//	return 0;
//}