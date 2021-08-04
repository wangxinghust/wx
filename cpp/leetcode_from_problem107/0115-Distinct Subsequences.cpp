#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 递归写法
class Solution {
	void recursion(string& s, string& t, int sCur, int tCur, int& sum) {
		if (tCur == t.size() - 1) {
			for (int i = sCur; i < s.size(); i++) {
				if (s[i] == t[tCur]) ++sum;
			}
		}
		else {
			for (int i = sCur; i < s.size(); i++) {
				if (s[i] == t[tCur]) {
					recursion(s, t, i + 1, tCur + 1, sum);
				}
			}
		}
	}
public:
	int numDistinct(string s, string t) {
		int sum = 0;
		recursion(s, t, 0, 0, sum);
		return sum;
	}
};

// dp
// we will build an array mem where mem[i+1][j+1] means that S[0..j] contains T[0..i] that many times as distinct subsequences.
// leetcode by balint
class Solution2 {
public:
	int numDistinct(string s, string t) {
		// array creation
		vector<vector<long long>> mem(t.size() + 1, vector<long long>(s.size() + 1, 0));

		// filling the first row: with 1s
		for (int j = 0; j < s.size() + 1; j++) {
			mem[0][j] = 1;
		}

		// the first column is 0 by default in every other rows but the first, which we need.
		for (int i = 0; i < t.size(); i++) {
			for (int j = 0; j < s.size(); j++) {
				if (t[i] == s[j]) {
					mem[i + 1][j + 1] = mem[i][j] + mem[i + 1][j];
				}
				else {
					mem[i + 1][j + 1] = mem[i + 1][j];
				}
			}
		}
		for (int i = 0; i < t.size() + 1; i++) {
			for (int j = 0; j < s.size() + 1; j++) {
				cout << mem[i][j] << " ";
			}
			cout << endl;
		}
		return (int)mem[t.size()][s.size()];
	}
};


//int main() {
//	//string s = "rabbbit";
//	//string t = "rabbit";
//	string s = "babgbag";
//	string t = "bag";
//	// 特殊用例，递归会超时
//	//"adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc"
//	//"bcddceeeebecbc"
//	int sum = Solution2().numDistinct(s, t);
//	return 0;
//}