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

	//���ص�ģʽƥ���㷨 �հ�δ��д
	int Index(string haystack, string needle, int pos) {
		int i = pos;//i��������haystack�е�ǰλ���±꣬��pos��Ϊ0�����posλ�ÿ�ʼƥ��
		int j = 0;//j�����Ӵ�needle�е�ǰλ�õ��±�ֵ
		while (i < haystack.size() && j < needle.size()) {
			if (haystack[i] == needle[j]) {
				++i;
				++j;
			}
			else {//ָ��������¿�ʼƥ��
				i = i - j + 1;//i�˻ص��ϴ�ƥ����λ����һλ
				j = 0;//j�˻ص��Ӵ�needle����λ
			}			
		}
		if (j > needle.size()) {
			return i - needle.size();
		}
		else {
			return -1;
		}
	}

	//leetcode kmpProcessl�㷨 ���ڡ������ݽṹ���Ľ����ϵĸĽ�
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
				return i - j;//j���ף�����i����j���λ��
			}
			if (i < m && haystack[i] != needle[j]) {
				j ? j = lps[j - 1] : i++;//j=0ʱ��i++��������һ���ַ�ƥ�䣬j!=0ʱ��j����
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
				len = lps[len - 1];//����len��ѭ���ж�needl[i]==needle[len]
			}
			else {
				lps[i++] = 0;
			}
		}
		return lps;
	}

	//KMP�㷨 �������ݽṹ���� ̫������ δ�Ľ� ����
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
			else if (j) {//j!=0�����
				j = next[j];
			}
			else {//j==0�������һ��
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