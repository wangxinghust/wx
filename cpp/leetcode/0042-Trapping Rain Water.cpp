#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
	int trap1(vector<int>& height) {
		if (height.size() < 3) return 0;
		vector<int> peak;
		int left = 0, right = height.size() - 1;
		for (int i = 0; i < height.size() - 1; ++i) {
			if (height[i] > height[i + 1]) {
				left = i;
				peak.push_back(left);
				break;
			}
		}
		for (int i = height.size() - 1; i >= 1; --i) {
			if (height[i] > height[i - 1]) {
				right = i;
				break;
			}
		}
		if (left == right) return 0;
		int mid = left, midValue = height[left];
		for (int i = left + 1; i < right; ++i) {
			if (height[i] > midValue) {
				midValue = height[i];
				mid = i;
			}
		}
		for (int i = left + 1; i < mid; ++i) {
			if (height[i] > height[i + 1] && height[i] > height[left]) {
				peak.push_back(i);
				left = i;
			}
		}
		if (mid != left) {
			peak.push_back(mid);
		}
		vector<int> peakTmp;
		if (mid != right) {
			peakTmp.push_back(right);
		}
		for (int i = right - 1; i > mid; --i) {
			if (height[i] > height[i - 1] && height[i] > height[right]) {
				peakTmp.push_back(i);
				right = i;
			}
		}
		reverse(peakTmp.begin(),peakTmp.end());
		peak.insert(peak.end(), peakTmp.begin(),peakTmp.end());		

		int water = 0;
		for (int i = 0; i < peak.size() - 1; ++i) {
			int tmp = min(height[peak[i]], height[peak[i + 1]]);
			for (int j = peak[i] + 1; j < peak[i + 1]; ++j) {
				water += height[j] < tmp ? tmp - height[j] : 0;
			}
		}
		return water;
	}

	//leetcode Approach 1: Brute force
	//Runtime: 336 ms, faster than 5.06 % of C++ online submissions for Trapping Rain Water.
	//Memory Usage : 9.1 MB, less than 82.12 % of C++ online submissions for Trapping Rain Water.
	int trap2(vector<int>& height) {
		int ans = 0, size = height.size();
		//对每一格进行循环 去掉两头
		for (int i = 1; i < size - 1; ++i) {
			int max_left = 0, max_right = 0;
			for (int j = i; j >= 0; --j) {//向左搜最大的一个值
				max_left = max(max_left, height[j]);
			}
			for (int j = i; j < size; ++j) {//向右搜最大的一个值
				max_right = max(max_right, height[j]);
			}
			//则这个格子能承受的雨水确定了
			ans += min(max_left, max_right) - height[i];
		}
		return ans;
	}

	//Approach 2: Dynamic Programming
	//Runtime: 12 ms, faster than 48.64 % of C++ online submissions for Trapping Rain Water.
	//Memory Usage : 9.2 MB, less than 70.23 % of C++ online submissions for Trapping Rain Water.
	int trap3(vector<int>& height) {
		if (height.size() == 0) return 0;
		int ans = 0;
		int size = height.size();

		//既然用到很多次最大值，直接一次计算左右位置的左最大值和右最大值，即为动态规划
		vector<int> left_max(size), right_max(size);
		left_max[0] = height[0];
		for (int i = 1; i < size; ++i) {
			left_max[i] = max(height[i], left_max[i - 1]);
		}
		right_max[size - 1] = height[size - 1];
		for (int i = size - 2; i >= 0; --i) {
			right_max[i] = max(height[i], right_max[i + 1]);
		}
		//遍历增加
		for (int i = 1; i < size - 1; ++i) {
			ans += min(left_max[i], right_max[i]) - height[i];
		}
		return ans;
	}

	//Approach 3: Using stacks
	//Runtime: 4 ms, faster than 99.51% of C++ online submissions for Trapping Rain Water.
	//Memory Usage : 9.5 MB, less than 56.42 % of C++ online submissions for Trapping Rain Water.
	int trap4(vector<int>& height) {
		int ans = 0, current = 0;
		stack<int> st;
		while (current < height.size()) {
			//当前值比栈里存的值更大，则取出，并计算这一段能存储的值，并不断从栈里取值做比较
			//显然，栈里的值存的是一个不断减小的序列，否则会被取出
			while (!st.empty() && height[current] > height[st.top()]) {
				int top = st.top();//top为池底
				st.pop();
				//如果栈里只有一个元素，被取出后为空，显然不能计算距离和高度
				if (st.empty())
					break;
				int distance = current - st.top() - 1;
				int bounded_height = min(height[current], height[st.top()]) - height[top];
				ans += distance * bounded_height;
			}
			//存入当前值
			st.push(current++);
		}
		return ans;
	}


	//Approach 4: Using 2 pointers
	//Runtime: 8 ms, faster than 93.22% of C++ online submissions for Trapping Rain Water.
	//Memory Usage : 9.1 MB, less than 77.95 % of C++ online submissions for Trapping Rain Water.
	int trap(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int ans = 0;
		int left_max = 0, right_max = 0;
		while (left < right) {
			//方法二里是取左最大值和右最大值的较小值，那这儿先行比较那边更小 保证了最大值在中间
			if (height[left] < height[right]) {
				height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
				++left;
			}
			else {
				height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
				--right;
			}
		}
		return ans;
	}
};


//int main(int argc, char* argv[]) {
//	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
//	Solution s;
//	int water = s.trap(height);
//	return 0;
//}