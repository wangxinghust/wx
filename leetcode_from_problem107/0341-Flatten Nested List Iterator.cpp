#include <stack>
#include <vector>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger>& getList() const;
};

// Runtime: 20 ms, faster than 75.39% of C++ online submissions for Flatten Nested List Iterator.
// Memory Usage : 19.2 MB, less than 14.26 % of C++ online submissions for Flatten Nested List Iterator.
class NestedIterator {
	stack<NestedInteger> nodes;
public:
	NestedIterator(vector<NestedInteger>& nestedList) {
		// 从后往前存入stack
		int size = nestedList.size();
		for (int i = size - 1; i >= 0; --i) {
			nodes.push(nestedList[i]);
		}
	}

	int next() {
		int result = nodes.top().getInteger();
		nodes.pop();
		return result;
	}

	bool hasNext() {
		// 循环判定，直到有整数，跳出循环，说明没有
		while (!nodes.empty()) {
			NestedInteger curr = nodes.top();
			// 如果是整数，那返回true
			if (curr.isInteger()) {
				return true;
			}
			nodes.pop();
			// 如果不是整数，getList，再从后往前添加到stack里
			vector<NestedInteger> adjs = curr.getList();
			int size = adjs.size();
			for (int i = size - 1; i >= 0; --i) {
				nodes.push(adjs[i]);
			}
		}

		return false;
	}
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */