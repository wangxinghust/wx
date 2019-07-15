#include <set>
using namespace std;

// Runtime: 4 ms, faster than 78.14% of C++ online submissions for Happy Number.
// Memory Usage : 8.4 MB, less than 52.33 % of C++ online submissions for Happy Number.
class Solution {
public:
	bool isHappy(int n) {
		set<int> data;
		data.insert(n);
		while (n != 1) {
			int sum = 0;
			while (n) {
				int reminder = n % 10;
				n /= 10;				
				sum += reminder * reminder;
			}
			n = sum;
			if (data.find(n) != data.end()) {
				return false;
			}
			else data.insert(n);
		}
		return true;
	}
};


// leetcode by Freezen: Floyd Cycle detection algorithm
// ������ Linked List Cycle detection problem ��������1���������1��ѭ�����ҵ�ѭ���������㣬�ж����������Ƿ���1����
// Runtime: 4 ms, faster than 78.14% of C++ online submissions for Happy Number.
// Memory Usage : 8.2 MB, less than 68.33 % of C++ online submissions for Happy Number.
class Solution2{
	int digitSquareSum(int n) {
		int sum = 0, tmp;
		while (n) {
			tmp = n % 10;
			sum += tmp * tmp;
			n /= 10;
		}
		return sum;
	}
public:
	bool isHappy(int n) {
		int slow, fast;
		slow = fast = n;
		do {
			slow = digitSquareSum(slow);
			fast = digitSquareSum(fast);
			fast = digitSquareSum(fast);
		} while (slow != fast);
		if (slow == 1) return 1;
		else return 0;
	}
};