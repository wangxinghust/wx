#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	//思路 写一个移动至第一个左括号的函数（在s的某段区间内）
	//找第一个左括号
	//双指针，一个插旗，一个往后移动，计算双指针差值为len，循环取最大值，len初始为0
	//往后遍历，如果遍历到）的数量大于（，则从该）后再找第一个（开始遍历计算
	//往后遍历，如果遍历到末尾，（的数量大于），则移至下一个左括号重新遍历
	int longestValidParentheses1(string s) {
		unsigned int ahead, rear;
		rear = ahead = firstLeftParenthesis(s, 0);
		unsigned int len = 0;
		while (ahead < s.length()) {
			int count = 0;
			for (rear = ahead; rear < s.length(); ++rear) {
				if (s[rear] == '(') ++count;
				else --count;
				if (count == 0) len = max(len, rear - ahead + 1);
				if (count < 0) break;
			}
			if (count < 0) ahead = firstLeftParenthesis(s, rear);
			else ahead = firstLeftParenthesis(s, ahead + 1);
		}
		return len;
	}
	int firstLeftParenthesis(string s, int index) {
		for (int i = index; i < s.length(); ++i) {
			if (s[i] == '(') return i;
		}
		return s.length();
	}


	//leetcode Approach 2:Using Dynamic Programming
	int longestValidParentheses2(string s) {
		int maxans = 0;
		vector<int> dp(s.length(), 0);
		for (int i = 1; i < s.length(); ++i) {
			if (s[i] == ')') {
				if (s[i - 1] == '(') {
					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
				}
				else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
					dp[i] = dp[i - 1] + ((i - dp[i - 1] - 2) >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
				}
				maxans = max(maxans, dp[i]);
			}
		}
		return maxans;
	}

	//leetcode Approach 3:Using Stack
	int longestValidParentheses3(string s) {
		int maxans = 0;
		stack<int> stack1;
		stack1.push(-1);
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(') {
				stack1.push(i);
			}
			else {
				stack1.pop();
				if (stack1.empty()) {
					stack1.push(i);
				}
				else {
					maxans = max(maxans, i - stack1.top());
				}
			}
		}
		return maxans;
	}

	//leetcode Approach 4: Without extra space
	//与自己最初的想法类似
	int longestValidParentheses(string s) {
		int left = 0, right = 0, maxLength = 0;
		//from left to right
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(') {
				++left;
			}
			else {
				++right;
			}
			if (left == right) {
				maxLength = max(maxLength, 2 * right);
			}
			else if (right > left) {
				left = right = 0;
			}
		}
		//from right to left
		left = right = 0;
		for (int i = s.length() - 1; i >= 0; --i) {
			if (s[i] == '(') {
				++left;
			}
			else {
				++right;
			}
			if (left == right) {
				maxLength = max(maxLength, 2 * left);
			}
			else if (left > right) {
				left = right = 0;
			}
		}
		return maxLength;
	}
};

//int main(int argc, char* argv[]) {
//	string str = "(()";
//	Solution s;
//	int n = s.longestValidParentheses(str);
//	return 0;
//}