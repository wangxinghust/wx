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
			//�������
			if (hasChar.find(s[j]) != hasChar.end())
			{
				//���max�������жϣ��ظ���ֵ��i��ǰ�滹�Ǻ��棬��ǰ��Ļ��������޸�
				i = max(hasChar[s[j]], i);
			}
			ans = max(ans, j - i + 1);
			//map�±��������������ڣ��򴴽�������Ĭ��ֵ���ٸ�ֵ��������ڣ����޸�ֵ
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