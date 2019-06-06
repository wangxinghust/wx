#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	//Runtime: 8 ms, faster than 91.96% of C++ online submissions for Simplify Path.
	//Memory Usage : 9.4 MB, less than 97.56 % of C++ online submissions for Simplify Path.
	string simplifyPath(string path) {
		int pos = 0, after = 0;
		int len = path.length();
		string ans;
		while (pos < len && after < len) {
			pos = path.find_first_not_of('/', after);
			if (pos == string::npos) break;
			after = path.find_first_of('/', pos);
			after = after == string::npos ? len : after;
			string tmp = path.substr(pos, after - pos);
			if (tmp == ".") {
				continue;
			}
			else if (tmp == "..") {
				if (!ans.empty()) {
					ans.erase(ans.find_last_of('/'));
				}
			}
			else {
				ans += '/' + tmp;
			}
		}
		if (ans.empty()) {
			ans += '/';
		}
		return ans;
	}
};

//int main(int argc, char* argv[]) {
//	vector<string> path = { "/home/" ,"/../" ,"/home//foo/" ,"/a/./b/../../c/" ,"/a/../../b/../c//.//" ,"/a//b////c/d//././/.." };
//	Solution s;
//	vector<string> ans;
//	for (string str : path) {
//		ans.push_back(s.simplifyPath(str));
//	}
//	return 0;
//}