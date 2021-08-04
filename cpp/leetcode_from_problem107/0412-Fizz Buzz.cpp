#include <vector>
#include <string>
#include <map>
using namespace std;

// Runtime: 8 ms, faster than 70.02% of C++ online submissions for Fizz Buzz.
// Memory Usage : 10.4 MB, less than 26.33 % of C++ online submissions for Fizz Buzz.
class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> ret;
		for (int i = 1; i <= n; ++i) {
			if (i % 15 == 0) {
				ret.push_back("FizzBuzz");
			}
			else if (i % 5 == 0) {
				ret.push_back("Buzz");
			}
			else if (i % 3 == 0) {
				ret.push_back("Fizz");
			}
			else {
				ret.push_back(to_string(i));
			}
		}
		return ret;
	}
};

// Approach 2: String Concatenation

// Approach 3: Hash it!

class Solution2 {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> ans;

		// hash map to store all fizzbuzz mappings
		map<int, string> fizzBizzDict = { {3,"Fizz"},{5,"Buzz"} };
		for (int num = 1; num <= n; num++) {
			string numAnsStr = "";
			for (auto keyValue : fizzBizzDict) {
				// if the num is divisible by key,
				// then add the corresponding string mapping to current numAnsStr
				if (num % keyValue.first == 0)
					numAnsStr += keyValue.second;
			}
			if (numAnsStr == "") {
				// not divisible by 3 or 5, add the number
				numAnsStr += to_string(num);
			}
			ans.push_back(numAnsStr);
		}
		return ans;
	}
};

//int main(int argc, char* argv[]) {
//	vector<string> ret = Solution2().fizzBuzz(1);
//	return 0;
//}