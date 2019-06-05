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
				//+1��ʾ�ո�
				len = len + 1 + words[wordsNext].length();
				if (len > maxWidth) {
					break;
				}
				++wordsNext;
			}
			//��������β��
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
				//ֻ��һ���ʣ�����뼴��
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
						//��һ�����ź���һ�����ŵ�
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
			//��k��l��ʾ����ֵ
			for (k = l = 0; i + k < words.size() and l + words[i + k].size() <= maxWidth - k; k++) {
				//�ж�����maxWidth-k��ȥ���м�Ŀո���ռ����
				l += words[i + k].size();
			}
			string tmp = words[i];
			for (int j = 0; j < k - 1; j++) {
				//���һ�У�ÿ�����ʼ�+1�ո�
				if (i + k >= words.size()) tmp += " ";
				//j < (maxWidth - l) % (k - 1)���ڷ������Ŀո�(ps: l��1���׻���)
				else tmp += string((maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1)), ' ');

				tmp += words[i + j + 1];
			}
			//��maxWidth-tmp.size()���ƹ����������˶�����жϣ������ʱ����ո��Ҷ���ʱ maxWidth-tmp.size() Ϊ0
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