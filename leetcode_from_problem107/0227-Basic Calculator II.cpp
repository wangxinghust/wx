using namespace std;
#include <string>
#include <stack>

// Runtime: 16 ms, faster than 68.64% of C++ online submissions for Basic Calculator II.
// Memory Usage : 11 MB, less than 31.06 % of C++ online submissions for Basic Calculator II.
class Solution {
public:
	int calculate(string s) {
		int i = 0;
		stack<int> nums;
		stack<char> op;
		while (i < s.length()) {
			int num = 0;
			while (i < s.length() && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/') {
				if (s[i] != ' ') {
					// ¼ÓÀ¨ºÅ±Ü¿ªÒç³ö
					num = num * 10 + (s[i] - '0');
				}
				++i;
			}
			if (!op.empty() && (op.top() == '*' || op.top() == '/')) {

				int b = num;
				int a = nums.top();
				nums.pop();
				num = op.top() == '*' ? a * b : a / b;
				// ËãÍê³Ë³ýµ¯³ö³Ë³ý·ûºÅ
				op.pop();
			}
			nums.push(num);
			if (i < s.length()) {
				op.push(s[i++]);
			}
		}
		// Ëã¼Ó¼õ
		int result = 0;
		while (!op.empty()) {
			int num = nums.top();
			result = op.top() == '+' ? result + num : result - num;
			nums.pop();
			op.pop();
		}		
		return nums.top() + result;
	}
};

//int main(int argc, char* argv[]) {
//	//int ret = Solution().calculate("3+2*2");
//	//int ret = Solution().calculate("2147483647");
//	int ret = Solution().calculate("1-1+1");
//	return 0;
//}