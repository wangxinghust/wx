#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Runtime: 8 ms, faster than 73.23% of C++ online submissions for Expressive Words.
// Memory Usage : 9.8 MB, less than 42.86 % of C++ online submissions for Expressive Words.
class Solution {
	bool isStretchy(string s, string w) {
		// 惯例判定
		if (s.empty() || w.empty()) return false;
		// 声明两个 index 分别指向 string s 和 string w
		int s_index = 0, w_index = 0;
		while (s_index < s.size() && w_index < w.size()) {
			// 找 w 中重复的度
			int num_repet = 0;
			// 循环到最后一个重复的 char
			while (w_index + 1 < w.size() && w[w_index + 1] == w[w_index]) {
				w_index++;
				num_repet++;
			}
			// 判断 num_repet 区间是否满足相等的要求，不满足则返回 false
			for (int i = 0; i < num_repet + 1; i++) {
				if (s_index + i >= s.size() || s[s_index + i] != w[w_index]) return false;
			}
			// w_index 指向的字符无重复，则判断后两个字符是否相同
			if (num_repet == 0) {
				if (s_index + 2 < s.size() && s[s_index + 1] == w[w_index]) {
					if (s[s_index + 2] != w[w_index]) return false;
					// 满足以上要求后，将 s_index 移至最后一个重复的 char
					while (s_index + 1 < s.size() && s[s_index + 1] == s[s_index]) s_index++;
				}
			}
			// 有重复时，前面已判断过重复区内是否相等，仅需将 s_index 移至最后一个重复的 char 即可
			// 针对 dd 这类情况，s 中 ddd/dd均可，也就是只需要移动 s_index
			else {
				while (s_index + 1 < s.size() && s[s_index + 1] == s[s_index]) s_index++;
			}

			// 循环内最后一步，将 w_index 和 s_index 分别移至后一个不同的 char
			w_index++;
			s_index++;
		}
		// 判断 s 和 w 是否都恰好遍历完
		if (s_index != s.size() || w_index != w.size()) return false;
		return true;
	}
public:
	int expressiveWords(string S, vector<string>& words) {
		int ans = 0;
		for (string word : words) {
			if (isStretchy(S, word)) ans++;
		}
		return ans;
	}
};

// Approach #1: Run Length Encoding [Accepted]
// Runtime: 12 ms, faster than 29.55% of C++ online submissions for Expressive Words.
// Memory Usage : 10.7 MB, less than 42.86 % of C++ online submissions for Expressive Words.
class RLE {
public:
	string key;
	vector<int> counts;

	RLE(string s) {
		int prev = -1;
		for (int i = 0; i < s.size(); i++) {
			if (i == s.size() - 1 || s[i] != s[i + 1]) {
				key += s[i];
				counts.push_back(i - prev);
				prev = i;
			}
		}
	}
};
class Solution2 {
	bool isStretchy(RLE* r1, RLE* r2) {
		if (r1->key != r2->key) return false;
		for (int i = 0; i < r1->counts.size(); i++) {
			if (r1->counts[i] < 3 && r1->counts[i] != r2->counts[i] || r1->counts[i] < r2->counts[i])
				return false;
		}
		return true;
	}
public:
	int expressiveWords(string S, vector<string>& words) {
		RLE* r1 = new RLE(S);
		int ans = 0;
		for (string w : words) {
			RLE* r2 = new RLE(w);
			if (isStretchy(r1, r2)) ans++;
			delete r2;
		}
		delete r1;
		return ans;
	}
};


int main(int argc, char* argv[]) {
	/*string S = "heeellooo";
	vector<string> words = { "hello","hi","helo" };*/
	string S = "dddiiiinnssssssoooo";
	vector<string> words = { "dinnssoo","ddinso","ddiinnso","ddiinnssoo","ddiinso","dinsoo","ddiinsso","dinssoo","dinso" };
	cout << Solution2().expressiveWords(S, words);
	return 0;
}