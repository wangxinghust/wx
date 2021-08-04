#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.length() <= 0) {
			return true;
		}
		stack<char> stack1;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				stack1.push(s[i]);
			}
			else if (s[i] == ')') {
				if (stack1.empty() || stack1.top() != '(') {
					return false;
				}
				else {
					stack1.pop();
				}
			}
			else if (s[i] == ']') {
				if (stack1.empty() || stack1.top() != '[') {
					return false;
				}
				else {
					stack1.pop();
				}
			}
			else if (s[i] == '}') {
				if (stack1.empty() || stack1.top() != '{') {
					return false;
				}
				else {
					stack1.pop();
				}
			}
			else {
				return false;
			}
		}
		if (!stack1.empty()) {
			return false;
		}
		return true;
	}
};


//int main(int argc, char* argv[]) {
//	Solution s;
//	string str = "){";
//	bool b = s.isValid(str);
//	return 0;
//}