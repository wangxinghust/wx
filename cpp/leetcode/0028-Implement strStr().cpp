#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int strStr1(string haystack, string needle) {
		if (needle.length() == 0) return 0;
		if (haystack.length() == 0) return -1;
		for (int i = 0; i < (int)haystack.length() - (int)needle.length() + 1; ++i) {
			if (isMatch(haystack, i, needle)) return i;
		}
		return -1;
	}
	bool isMatch(string haystack, int i, string needle) {
		for (int j = 0; j < (int)needle.length(); ++j, ++i) {
			if (haystack[i] != needle[j]) return false;
		}
		return true;
	}

	//朴素的模式匹配算法 照搬未重写
	int Index(string haystack, string needle, int pos) {
		int i = pos;//i用于主串haystack中当前位置下标，若pos不为0，则从pos位置开始匹配
		int j = 0;//j用于子串needle中当前位置的下标值
		while (i < haystack.size() && j < needle.size()) {
			if (haystack[i] == needle[j]) {
				++i;
				++j;
			}
			else {//指针后退重新开始匹配
				i = i - j + 1;//i退回到上次匹配首位的下一位
				j = 0;//j退回到子串needle的首位
			}			
		}
		if (j > needle.size()) {
			return i - needle.size();
		}
		else {
			return -1;
		}
	}

	//leetcode kmpProcessl算法 是在《大话数据结构》改进版上的改进
	int strStr2(string haystack, string needle) {
		int m = haystack.size(), n = needle.size();
		//needle==""
		if (!n) {
			return 0;
		}
		vector<int> lps = kmpProcess(needle);
		for (int i = 0, j = 0; i < m;) {
			if (haystack[i] == needle[j]) {
				i++, j++;
			}
			if (j == n) {
				return i - j;//j到底，返回i回退j格的位置
			}
			if (i < m && haystack[i] != needle[j]) {
				j ? j = lps[j - 1] : i++;//j=0时，i++，继续下一个字符匹配，j!=0时，j回溯
			}
		}
		return -1;
	}
	vector<int> kmpProcess(string needle) {
		int n = needle.size();
		vector<int> lps(n, 0);
		for (int i = 1, len = 0; i < n;) {
			if (needle[i] == needle[len]) {
				lps[i++] = ++len;
			}
			else if (len) {
				len = lps[len - 1];//回溯len，循环判断needl[i]==needle[len]
			}
			else {
				lps[i++] = 0;
			}
		}
		return lps;
	}

	//KMP算法 《大话数据结构》版 太烦心了 未改进 可能
	vector<int> kmpProcess1(string needle) {
		int n = needle.size();
		vector<int> next(n, 0);
		int i = 1;
		int j = 0;
		while (i < n) {
			if (needle[i] == needle[j]) {
				++j;
				next[i] = j;
				++i;
			}
			else if (j) {//j!=0则回退
				j = next[j];
			}
			else {//j==0则计算下一个
				next[i] = 0;
				++i;
			}
		}
		return next;
	}
};

//int main(int argc, char* argv[]) {
//	string haystack = "hello";
//	string needle = "ababaaaba";
//	Solution s;
//	vector<int> next;
//	next = s.kmpProcess(needle);
//	int index = s.strStr2(haystack, needle);
//	return 0;
//}