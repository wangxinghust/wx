#include <vector>
#include <string>
#include <deque>
#include <map>
using namespace std;

class Solution {
public:
	//by wx
	vector<string> letterCombinations1(string digits) {
		vector<string> ans;
		if (digits.length() < 0) {
			return ans;
		}
		deque<string> ansQueue;
		switch (digits[0]) {
		case '2':
			ansQueue.push_back("a");
			ansQueue.push_back("b");
			ansQueue.push_back("c");
			break;
		case '3':
			ansQueue.push_back("d");
			ansQueue.push_back("e");
			ansQueue.push_back("f");
			break;
		case '4':
			ansQueue.push_back("g");
			ansQueue.push_back("h");
			ansQueue.push_back("i");
			break;
		case '5':
			ansQueue.push_back("j");
			ansQueue.push_back("k");
			ansQueue.push_back("l");
			break;
		case '6':
			ansQueue.push_back("m");
			ansQueue.push_back("n");
			ansQueue.push_back("o");
			break;
		case '7':
			ansQueue.push_back("p");
			ansQueue.push_back("q");
			ansQueue.push_back("r");
			ansQueue.push_back("s");
			break;
		case '8':
			ansQueue.push_back("t");
			ansQueue.push_back("u");
			ansQueue.push_back("v");
			break;
		case '9':
			ansQueue.push_back("w");
			ansQueue.push_back("x");
			ansQueue.push_back("y");
			ansQueue.push_back("z");
			break;
		default:
			return ans;
		}
		for (int i = 1; i < digits.size(); ++i) {
			int n = ansQueue.size();
			switch (digits[i]) {
			case '2':
				for (int i = 0; i < n; ++i) {
					string tmp = ansQueue.front();
					ansQueue.pop_front();
					ansQueue.push_back(tmp + "a");
					ansQueue.push_back(tmp + "b");
					ansQueue.push_back(tmp + "c");
				}
				break;
			case '3':
				for (int i = 0; i < n; ++i) {
					string tmp = ansQueue.front();
					ansQueue.pop_front();
					ansQueue.push_back(tmp + "d");
					ansQueue.push_back(tmp + "e");
					ansQueue.push_back(tmp + "f");
				}
				break;
			case '4':
				for (int i = 0; i < n; ++i) {
					string tmp = ansQueue.front();
					ansQueue.pop_front();
					ansQueue.push_back(tmp + "g");
					ansQueue.push_back(tmp + "h");
					ansQueue.push_back(tmp + "i");
				}
				break;
			case '5':
				for (int i = 0; i < n; ++i) {
					string tmp = ansQueue.front();
					ansQueue.pop_front();
					ansQueue.push_back(tmp + "j");
					ansQueue.push_back(tmp + "k");
					ansQueue.push_back(tmp + "l");
				}
				break;
			case '6':
				for (int i = 0; i < n; ++i) {
					string tmp = ansQueue.front();
					ansQueue.pop_front();
					ansQueue.push_back(tmp + "m");
					ansQueue.push_back(tmp + "n");
					ansQueue.push_back(tmp + "o");
				}
				break;
			case '7':
				for (int i = 0; i < n; ++i) {
					string tmp = ansQueue.front();
					ansQueue.pop_front();
					ansQueue.push_back(tmp + "p");
					ansQueue.push_back(tmp + "q");
					ansQueue.push_back(tmp + "r");
					ansQueue.push_back(tmp + "s");
				}
				break;
			case '8':
				for (int i = 0; i < n; ++i) {
					string tmp = ansQueue.front();
					ansQueue.pop_front();
					ansQueue.push_back(tmp + "t");
					ansQueue.push_back(tmp + "u");
					ansQueue.push_back(tmp + "v");
				}
				break;
			case '9':
				for (int i = 0; i < n; ++i) {
					string tmp = ansQueue.front();
					ansQueue.pop_front();
					ansQueue.push_back(tmp + "w");
					ansQueue.push_back(tmp + "x");
					ansQueue.push_back(tmp + "y");
					ansQueue.push_back(tmp + "z");
				}
				break;
			default:
				return ans;
			}
		}
		ans.assign(ansQueue.begin(), ansQueue.end());
		return ans;
	}
	//TODO: reconsitution by map

	//backtracking
	map<string, string> phone = {
		{"2","abc"},
		{"3","def"},
		{"4","ghi"} ,
		{"5","jkl"} ,
		{"6","mno"} ,
		{"7","pqrs"} ,
		{"8","tuv"} ,
		{"9","wxyz"}
	};
	vector<string> output;
	vector<string> letterCombinations(string digits) {
		if (digits.length() != 0) {
			backtrack("", digits);
		}
		return output;
	}
	void backtrack(string combination, string next_digits) {
		//if there is no more digits to check
		if (next_digits.length() == 0) {
			//the combination is done
			output.push_back(combination);
		}
		//if there are still digits to check
		else {
			//iterate over all letters whick map
			//the next available digit
			string digit = next_digits.substr(0, 1);
			string letters = phone.at(digit);
			for (int i = 0; i < letters.length(); ++i) {
				string letter = phone.at(digit).substr(i, 1);
				//append the current letter to the combination
				//and proceed to the next digits
				backtrack(combination + letter, next_digits.substr(1));
			}
		}
	}
};

//int main(int argc, char* argv[]) {
//	Solution s;
//	string digits = "23";
//	vector<string> ans;
//	ans = s.letterCombinations(digits);
//	return 0;
//}