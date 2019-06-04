#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis1(int n) {
		vector<string> ans;
		if (n <= 0) {
			return ans;
		}
		else {

		}
	}


	//leetcode Approach:Brute Force
	vector<string> generateParenthesis2(int n) {
		vector<string> combinations;
		vector<char> current(2 * n);
		generateAll(current, 0, combinations);
		return combinations;
	}
	void generateAll(vector<char> current, int pos, vector<string> &result) {
		if (pos == current.size()) {
			string str(current.begin(), current.end());
			if (isValid(current)) result.push_back(str);
		}
		else {
			current[pos] = '(';
			generateAll(current, pos + 1, result);
			current[pos] = ')';
			generateAll(current, pos + 1, result);
		}
	}
	bool isValid(vector<char> current) {
		int balance = 0;
		for (char c : current) {
			if (c == '(') balance++;
			else balance--;
			if (balance < 0) return false;
		}
		return (balance == 0);
	}

	//leetcode Approach:Backtracking
	vector<string> generateParenthesis(int n) {
		vector<string> combinations;
		backtrack(combinations, "", 0, 0, n);
		return combinations;
	}
	void backtrack(vector<string> &ans, string cur, int open, int close, int max) {
		if (cur.length() == max * 2) {
			ans.push_back(cur);
			return;
		}
		if (open < max) {
			backtrack(ans, cur + "(", open + 1, close, max);
		}
		//×¢Òâ ÊÇclose<open
		if (close < open) {
			backtrack(ans, cur + ")", open, close + 1, max);
		}
	}

	//leetcode Approach:Closure Number
	vector<string> generateParenthesis3(int n) {
		vector<string> ans;
		if (n == 0) {
			ans.push_back("");
		}
		else {
			for (int c = 0; c < n; ++c)
				for (string left : generateParenthesis3(c))
					for (string right : generateParenthesis3(n - 1 - c))
						ans.push_back("(" + left + ")" + right);
		}
		return ans;
	}

	vector<string> generateParenthesis4(int n) {
		vector<vector<string> >ans(n+1);
		ans[0].push_back("");
		ans[1].push_back("()");
		for (int i = 2; i <= n; ++i) {
			for (int c = 0; c < i; ++c) {
				for (string left : ans[c])
					for (string right : ans[i - 1 - c])
						ans[i].push_back("(" + left + ")" + right);
			}
		}
		return ans[n];
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	vector<string> combinations;
//	combinations = s.generateParenthesis4(3);
//	return 0;
//}