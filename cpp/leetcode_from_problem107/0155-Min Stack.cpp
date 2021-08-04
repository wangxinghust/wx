#include <stack>
#include <algorithm>
using namespace std;

// 剑指offer双栈解法
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		minCurrent = INT_MAX;
	}

	void push(int x) {
		data.push(x);
		minCurrent = min(minCurrent, x);
		minNum.push(minCurrent);
	}

	void pop() {
		data.pop();
		minNum.pop();
		minCurrent = !minNum.empty() ? minNum.top() : INT_MAX;
	}

	int top() {
		return data.top();
	}

	int getMin() {
		return minNum.top();
	}
private:
	stack<int> data;
	stack<int> minNum;
	int minCurrent;
};

// leetcode by YuSi: pair&&stack
// Runtime: 28 ms, faster than 94.24% of C++ online submissions for Min Stack.
// Memory Usage : 16.7 MB, less than 91.30 % of C++ online submissions for Min Stack.
class MinStack2 {
	stack<pair<int, int>> st;
public:
	void push(int x) {
		int minN;
		if (st.empty()) minN = x;
		else minN = min(st.top().second, x);
		st.push({ x,minN });
	}

	void pop() {
		st.pop();
	}

	int top() {
		return st.top().first;
	}

	int getMin() {
		return st.top().second;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 //int main(int argc, char* argv[]) {
 //	MinStack* obj = new MinStack();
 //	obj->push(2147483646);
 //	obj->push(2147483646);
 //	obj->push(2147483647);
 //	obj->top();
 //	obj->pop();
 //	obj->getMin();
 //	obj->pop();
 //	obj->getMin();
 //	obj->pop();
 //	obj->push(2147483647);
 //	obj->top();
 //	obj->getMin();
 //	obj->push(INT_MIN);
 //	obj->top();
 //	obj->getMin();
 //	obj->pop();
 //	obj->getMin();
 //
 //	return 0;
 //}