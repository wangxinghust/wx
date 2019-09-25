#include <vector>
#include <string>
#include <set>
using namespace std;

// Approach 1: Backtracking
// 递归方法的集大成者
// 每个左、右括号可以添加或者不
// 剪枝算法，遇到添加到导致表达式无效的右括号，可以提前终止它的向下递归
// Runtime: 60 ms, faster than 39.79% of C++ online submissions for Remove Invalid Parentheses.
// Memory Usage : 14.8 MB, less than 45.83 % of C++ online submissions for Remove Invalid Parentheses.
class Solution {
private:
	set<string> validExpressions;
	int minimumRemoved;
	// 初始化函数
	void reset() {
		this->validExpressions.clear();
		this->minimumRemoved = INT_MAX;
	}
	void recurse(
		string& s,
		int index,
		int leftCount,
		int rightCount,
		string& expression,
		int removedCount) {
		// if we have reached the end of string
		if (index == s.length()) {
			// if the current expression is valid
			if (leftCount == rightCount) {
				// if the current count of removed parentheses is <= the current minimum count
				if (removedCount <= this->minimumRemoved) {
					// if the current count beats the overall minimum we have till now
					if (removedCount < this->minimumRemoved) {
						this->validExpressions.clear();
						this->minimumRemoved = removedCount;
					}
					this->validExpressions.insert(expression);
				}
			}
		}
		else {
			char currentCharacter = s[index];
			int length = expression.length();

			// if the current character is neither an opening bracket nor a closing one,
			// simply recurse further by adding it to the expression
			if (currentCharacter != '(' && currentCharacter != ')') {
				expression += currentCharacter;
				this->recurse(s, index + 1, leftCount, rightCount, expression, removedCount);
				// Removes the last character from the string.
				expression.pop_back();
			}
			else {
				// recursion where we delete the current character and move forward
				this->recurse(s, index + 1, leftCount, rightCount, expression, removedCount + 1);

				expression += currentCharacter;
				// if it's an opening parenthesis, consider it and recurse
				if (currentCharacter == '(') {
					this->recurse(s, index + 1, leftCount + 1, rightCount, expression, removedCount);
				}
				else if (rightCount < leftCount) {
					// for a closing parenthesis, only recurse if right < left
					this->recurse(s, index + 1, leftCount, rightCount + 1, expression, removedCount);
				}

				// undoing the append operation for other recursions
				expression.pop_back();
			}
		}
	}
public:
	// 加一个构造函数 使用前必初始化
	Solution() {
		this->validExpressions.clear();
		this->minimumRemoved = INT_MAX;
	}
	vector<string> removeInvalidParentheses(string s) {
		// 取消下列注释后，无法通过测试用例，如 "n"
		/*int i = 0;
		for (; i < s.length(); i++) {
			if (s[i] == '(') break;
		}
		s=s.substr(i);*/
		this->reset();
		string expression = ""; // 需要声明变量，直接在函数参数中输入""会报错，const string 无法修改
		this->recurse(s, 0, 0, 0, expression, 0);
		return vector<string>(this->validExpressions.begin(), this->validExpressions.end());
	}
};

// Approach 2: Limited Backtracking!
// 找出放错位置的左括号和右括号的数量
// 剪枝算法中可以加入对左括号和右括号移除数量的判定，同时调整结果判定条件
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Invalid Parentheses.
// Memory Usage : 10.7 MB, less than 62.50 % of C++ online submissions for Remove Invalid Parentheses.
class Solution2 {
private:
	set<string> validExpressions;
	/*int minimumRemoved;*/
	// 初始化函数
	/*void reset() {
		this->validExpressions.clear();
		this->minimumRemoved = INT_MAX;
	}*/
	void recurse(
		string& s,
		int index,
		int leftCount,
		int rightCount,
		int leftRem,
		int rightRem,
		string& expression) {
		// modified: 
		// if we have reached the end of string, just check if the resulting expression is
		// valid or not and also if we have removed the  total number of left and right
		// parentheses  that we should have remoeved.
		if (index == s.length()) {
			if (leftRem == 0 && rightRem == 0) {
				this->validExpressions.insert(expression);
			}
		}
		//if (index == s.length()) {
		//	// if the current expression is valid
		//	if (leftCount == rightCount) {
		//		// if the current count of removed parentheses is <= the current minimum count
		//		if (removedCount <= this->minimumRemoved) {
		//			// if the current count beats the overall minimum we have till now
		//			if (removedCount < this->minimumRemoved) {
		//				this->validExpressions.clear();
		//				this->minimumRemoved = removedCount;
		//			}
		//			this->validExpressions.insert(expression);
		//		}
		//	}
		//}
		else {
			char currentCharacter = s[index];
			int length = expression.length();

			// the discard case. Note that here we have our pruning condition.
			// we don't recurse if the remaining count for that parenthesis is ==0.
			if ((currentCharacter == '(' && leftRem > 0) || (currentCharacter == ')' && rightRem > 0)) {
				this->recurse(
					s,
					index + 1,
					leftCount,
					rightCount,
					leftRem - (currentCharacter == '(' ? 1 : 0),
					rightRem - (currentCharacter == ')' ? 1 : 0),
					expression);
			}

			expression += currentCharacter;

			// simply recurse one step further if the current character is not a parenthesis.
			if (currentCharacter != '(' && currentCharacter != ')') {
				this->recurse(s, index + 1, leftCount, rightCount, leftRem, rightRem, expression);
			}
			else if (currentCharacter == '(') {
				// consider an opening bracket.
				this->recurse(s, index + 1, leftCount + 1, rightCount, leftRem, rightRem, expression);
			}
			else if (rightCount < leftCount) {
				// consider a closing bracket.
				this->recurse(s, index + 1, leftCount, rightCount + 1, leftRem, rightRem, expression);
			}
			// delete for backtracking
			expression.pop_back();

			//// if the current character is neither an opening bracket nor a closing one,
			//// simply recurse further by adding it to the expression
			//if (currentCharacter != '(' && currentCharacter != ')') {
			//	expression += currentCharacter;
			//	this->recurse(s, index + 1, leftCount, rightCount, expression, removedCount);
			//	// Removes the last character from the string.
			//	expression.pop_back();
			//}
			//else {
			//	// recursion where we delete the current character and move forward
			//	this->recurse(s, index + 1, leftCount, rightCount, expression, removedCount + 1);

			//	expression += currentCharacter;
			//	// if it's an opening parenthesis, consider it and recurse
			//	if (currentCharacter == '(') {
			//		this->recurse(s, index + 1, leftCount + 1, rightCount, expression, removedCount);
			//	}
			//	else if (rightCount < leftCount) {
			//		// for a closing parenthesis, only recurse if right < left
			//		this->recurse(s, index + 1, leftCount, rightCount + 1, expression, removedCount);
			//	}

			//	// undoing the append operation for other recursions
			//	expression.pop_back();
			//}
		}
	}
public:
	vector<string> removeInvalidParentheses(string s) {
		int left = 0, right = 0;
		
		// first, we find out the number of misplaced left and right parentheses.
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				left++;
			}
			else if (s[i] == ')') {
				// if we don't have a matching left, then this is a misplaced right, record it.
				right = left == 0 ? right + 1 : right;

				// decrement count of left parentheses because we have found a right
				// which CAN be a matching one for a left.
				left = left > 0 ? left - 1 : left;
			}
		}

		string expression = "";
		this->recurse(s, 0, 0, 0, left, right, expression);

		return vector<string>(this->validExpressions.begin(), this->validExpressions.end());
	}
};

//int main() {
//	string s = "()())()";
//	vector<string> ans = Solution().removeInvalidParentheses(s);
//	return 0;
//}