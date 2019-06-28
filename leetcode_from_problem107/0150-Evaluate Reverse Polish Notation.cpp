#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <functional>
#include <cassert>
using namespace std;

// Runtime: 12 ms, faster than 94.56% of C++ online submissions for Evaluate Reverse Polish Notation.
// Memory Usage : 11.6 MB, less than 31.55 % of C++ online submissions for Evaluate Reverse Polish Notation.
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> nums;
		for (auto str : tokens) {
			if (str == "+" || str == "-" || str == "*" || str == "/") {
				int num1 = nums.top();
				nums.pop();
				int num2 = nums.top();
				nums.pop();
				if (str == "+") nums.push(num2 + num1);
				else if (str == "-") nums.push(num2 - num1);
				else if (str == "*") nums.push(num2 * num1);
				else if (str == "/") nums.push(num2 / num1);
			}
			else nums.push(stoi(str));
		}
		return nums.top();
	}
};

// leetcode by bevis
// Runtime: 16 ms, faster than 70.71% of C++ online submissions for Evaluate Reverse Polish Notation.
// Memory Usage : 11.5 MB, less than 65.63 % of C++ online submissions for Evaluate Reverse Polish Notation.
class Solution2 {
public:
	int evaRPN(vector<string>& tokens) {
		stack<int> s;
		unordered_map<string, function<int(int, int)>> map{
			{"+",plus<int>()},
			{"-",minus<int>()},
			{"*",multiplies<int>()},
			{"/",divides<int>()}
		};

		for (const auto& token : tokens) {
			const auto& op = map.find(token);
			if (op != map.end()) {
				assert(s.size() >= 2);
				int rhs = s.top(); s.pop();
				int lhs = s.top(); s.pop();
				s.push((*op).second(lhs, rhs));
			}
			else {
				s.push(stoi(token));
			}
		}

		assert(s.size() == 1);
		return s.top();
	}
};