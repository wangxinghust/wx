#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


class Solution {
public:
	//Sliding Window
	int lengthOfLongestSubstring(string s) {
		int len = s.length();
		set<char> hasChar;
		int ans = 0, i = 0, j = 0;
		while (i < len&&j < len)
		{
			if (hasChar.find(s[j]) == hasChar.end())
			{
				hasChar.insert(s[j++]);
				ans = max(ans, j - i);
			}
			else
			{
				hasChar.erase(s[i++]);
			}
		}
		return ans;
	}

	//Sliding Window Optimized
	int lengthOfLongestSubstring1(string s) {
		int n = s.length(), ans = 0;
		map<char, int> hasChar;
		for (int j = 0, i = 0; j < n; j++)
		{
			//如果包含
			if (hasChar.find(s[j]) != hasChar.end())
			{
				//这个max是用来判断，重复的值在i的前面还是后面，在前面的话，不用修改
				i = max(hasChar[s[j]], i);
			}
			ans = max(ans, j - i + 1);
			//map下标操作，如果不存在，则创建并存入默认值，再赋值，如果存在，则修改值
			hasChar[s[j]] = j + 1;
		}
		return ans;
	}

	int lengthOfLongestSubstring2(string s) {
		int n = s.length(), ans = 0;
		int index[256] = { 0 };
		for (int j = 0,i=0; j < n; j++)
		{
			i = max(index[s[j]], i);
			ans = max(ans, j - i + 1);
			index[s[j]] = j + 1;
		}
		return ans;
	}
};

//int main()
//{
//	string s = "abcabcbb";
//	Solution a;
//	int result = a.lengthOfLongestSubstring2(s);
//	return 0;
//}