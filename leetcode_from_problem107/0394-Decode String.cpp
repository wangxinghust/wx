#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

// Runtime: 4 ms, faster than 54.55% of C++ online submissions for Decode String.
// Memory Usage : 8.8 MB, less than 94.12 % of C++ online submissions for Decode String.
using namespace std;
class Solution {
public:
	string decodeString(string s) {
		string ans = "";
		stack<int> st;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '[') continue;
			if (isdigit(s[i])) {
				int num = s[i] - '0';
				while (s[++i] != '[') {
					num = num * 10 + s[i] - '0';
				}
				st.push(num);
				st.push(ans.size());
			}
			else if (isalpha(s[i])) {
				ans += s[i];
			}
			else if (s[i] == ']') {
				int index = st.top(); st.pop();
				int num = st.top(); st.pop();
				string sub = ans.substr(index);
				for (int i = 0; i < num - 1; i++) {
					ans += sub;
				}
			}
		}
		return ans;
	}
};

int main() {
	vector<string> test = {
		"3[a]2[bc]",
		"3[a2[c]]",
		"2[abc]3[cd]ef"
	};
	for (auto str : test) {
		cout << Solution().decodeString(str) << endl;
	}
	cout << endl;

	string leetcode = "100[leetcode]";
	string leetcode_result = "";
	for (int i = 0; i < 100; i++) {
		leetcode_result += "leetcode";
	}
	if (leetcode_result == Solution().decodeString(leetcode)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	return 0;
}