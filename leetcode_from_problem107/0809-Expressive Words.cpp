#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Runtime: 8 ms, faster than 73.23% of C++ online submissions for Expressive Words.
// Memory Usage : 9.8 MB, less than 42.86 % of C++ online submissions for Expressive Words.
class Solution {
	bool isStretchy(string s, string w) {
		// �����ж�
		if (s.empty() || w.empty()) return false;
		// �������� index �ֱ�ָ�� string s �� string w
		int s_index = 0, w_index = 0;
		while (s_index < s.size() && w_index < w.size()) {
			// �� w ���ظ��Ķ�
			int num_repet = 0;
			// ѭ�������һ���ظ��� char
			while (w_index + 1 < w.size() && w[w_index + 1] == w[w_index]) {
				w_index++;
				num_repet++;
			}
			// �ж� num_repet �����Ƿ�������ȵ�Ҫ�󣬲������򷵻� false
			for (int i = 0; i < num_repet + 1; i++) {
				if (s_index + i >= s.size() || s[s_index + i] != w[w_index]) return false;
			}
			// w_index ָ����ַ����ظ������жϺ������ַ��Ƿ���ͬ
			if (num_repet == 0) {
				if (s_index + 2 < s.size() && s[s_index + 1] == w[w_index]) {
					if (s[s_index + 2] != w[w_index]) return false;
					// ��������Ҫ��󣬽� s_index �������һ���ظ��� char
					while (s_index + 1 < s.size() && s[s_index + 1] == s[s_index]) s_index++;
				}
			}
			// ���ظ�ʱ��ǰ�����жϹ��ظ������Ƿ���ȣ����轫 s_index �������һ���ظ��� char ����
			// ��� dd ���������s �� ddd/dd���ɣ�Ҳ����ֻ��Ҫ�ƶ� s_index
			else {
				while (s_index + 1 < s.size() && s[s_index + 1] == s[s_index]) s_index++;
			}

			// ѭ�������һ������ w_index �� s_index �ֱ�������һ����ͬ�� char
			w_index++;
			s_index++;
		}
		// �ж� s �� w �Ƿ�ǡ�ñ�����
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