#include <set>
#include <unordered_set>
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
// 类似于 Linked List Cycle detection problem 如果结果是1，那最后在1里循环，找到循环的相遇点，判定相遇的数是否是1即可
// Runtime: 4 ms, faster than 78.14% of C++ online submissions for Happy Number.
// Memory Usage : 8.2 MB, less than 68.33 % of C++ online submissions for Happy Number.
class Solution2 {
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

// 快手笔试再次遇到，实测+=写成了=，导致测试用例能过，但无法通过后台数据
// Runtime: 4 ms, faster than 66.00% of C++ online submissions for Happy Number.
// Memory Usage : 8.5 MB, less than 57.69 % of C++ online submissions for Happy Number.
class Solution3 {
	unordered_set<int> s;
	bool isTarget(int n) {
		if (n == 1) {
			return true;
		}
		while (n != 1) {
			int sum = 0;
			while (n) {
				sum += (n % 10) * (n % 10);
				n /= 10;
			}
			if (sum == 1) {
				return true;
			}
			else if (s.find(sum) != s.end()) {
				return false;
			}
			else {
				s.insert(sum);
			}
			n = sum;
		}
		return true;
	}
public:
	bool isHappy(int n) {
		return isTarget(n);
	}
};