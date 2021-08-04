#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	//Runtime: 8 ms, faster than 17.03% of C++ online submissions for Text Justification.
	//Memory Usage : 9.4 MB, less than 5.10 % of C++ online submissions for Text Justification.
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int wordsIndex = 0;
		vector<string> ans;
		while (wordsIndex < words.size()) {
			int wordsNext = wordsIndex + 1;
			int len = words[wordsIndex].length();
			while (wordsNext < words.size()) {
				//+1表示空格
				len = len + 1 + words[wordsNext].length();
				if (len > maxWidth) {
					break;
				}
				++wordsNext;
			}
			//遍历到结尾处
			if (wordsNext == words.size()) {
				string tmp = words[wordsIndex];
				int tmpLen = words[wordsIndex].length();
				for (int i = wordsIndex + 1; i < wordsNext; ++i) {
					tmp += " " + words[i];
					tmpLen += words[i].length() + 1;
				}
				tmp += string(maxWidth - tmpLen, ' ');
				ans.push_back(tmp);
			}
			else {
				//只有一个词，左对齐即可
				if (wordsNext - wordsIndex == 1) {
					ans.push_back(words[wordsIndex] + string(maxWidth - words[wordsIndex].length(), ' '));
				}
				//fully (left and right) justified.
				else {
					string tmp = words[wordsIndex];
					int tmpLen = words[wordsIndex].length();
					for (int i = wordsIndex + 1; i < wordsNext; ++i) {
						tmpLen += words[i].length();
					}
					for (int i = wordsIndex + 1; i < wordsNext; ++i) {
						//多一个括号和少一个括号的
						if (i - wordsIndex - 1 < (maxWidth - tmpLen) % (wordsNext - wordsIndex - 1)) {
							tmp += string((maxWidth - tmpLen) / (wordsNext - wordsIndex - 1) + 1, ' ') + words[i];
						}
						else {
							tmp += string((maxWidth - tmpLen) / (wordsNext - wordsIndex - 1), ' ') + words[i];
						}
					}
					ans.push_back(tmp);
				}
			}
			wordsIndex = wordsNext;
		}
		return ans;
	}


	//leetcode by qddpx
	//For each line, I first figure out which words can fit in. According to the code, 
	//these words are words[i] through words[i+k-1]. Then spaces are added between the words. 
	//The trick here is to use mod operation to manage the spaces that can't be evenly distrubuted: 
	//the first (maxWidth-l) % (k-1) gaps acquire an additional space.

	//Runtime: 4 ms, faster than 88.67% of C++ online submissions for Text Justification.
	//Memory Usage : 9.1 MB, less than 51.69 % of C++ online submissions for Text Justification.
	vector<string> fullJustify2(vector<string>& words, int maxWidth) {
		vector<string> res;
		for (int i = 0, k, l; i < words.size(); i += k) {
			//找k，l表示长度值
			for (k = l = 0; i + k < words.size() and l + words[i + k].size() <= maxWidth - k; k++) {
				//判断里用maxWidth-k来去除中间的空格所占长度
				l += words[i + k].size();
			}
			string tmp = words[i];
			for (int j = 0; j < k - 1; j++) {
				//最后一行，每个单词间+1空格
				if (i + k >= words.size()) tmp += " ";
				//j < (maxWidth - l) % (k - 1)用于分配多余的空格(ps: l和1极易混淆)
				else tmp += string((maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1)), ' ');

				tmp += words[i + j + 1];
			}
			//用maxWidth-tmp.size()来绕过左对齐和两端对齐的判断，左对齐时补足空格，右对齐时 maxWidth-tmp.size() 为0
			tmp += string(maxWidth - tmp.size(), ' ');
			res.push_back(tmp);
		}
		return res;
	}
};

//int main(int argc, char* argv[]) {
//	//example1
//	vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
//	//example 2
//	vector<string> words2 = { "What","must","be","acknowledgment","shall","be" };
//	//example 3
//	vector<string> words3 = { "Science","is","what","we","understand","well","enough","to","explain",
//		 "to","a","computer.","Art","is","everything","else","we","do" };
//	Solution s;
//	vector<string> ans = s.fullJustify2(words2, 16);
//	return 0;
//}