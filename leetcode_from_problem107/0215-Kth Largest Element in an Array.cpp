#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

// ��ָoffer���ڿ��ŵĸĽ� ��������k����
//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		int start = 0;
//		int end = nums.size() - 1;
//		int index = partition(nums, start, end);
//		while (index != k - 1) {
//			if (index > k - 1) {
//				end = index - 1;
//				index = partition(nums, start, end);
//			}
//			else {
//				start = index + 1;
//				index = partition(nums, start, end);
//			}
//		}
//		return nums[index];
//	}
//private:
//	int partition(vector<int>& nums, int start, int end) {
//		int pivotkey = nums[start]; // ���ӱ�ĵ�һ����¼�������¼
//		while (start < end) {
//			while (start < end && nums[start] > pivotkey)
//				++start;
//			swap(nums[start], nums[end]); // ���������¼С�Ľ������߶�
//			while (start < end && nums[end] <= pivotkey)
//				--end;
//			swap(nums[start], nums[end]); // ���������¼��Ľ������Ͷ�
//		}
//		return start;
//	}
//};

// ֱ������
// Runtime: 8 ms, faster than 98.09% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage : 9.2 MB, less than 77.65 % of C++ online submissions for Kth Largest Element in an Array.
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), [](int a, int b) {return a > b; });
		return nums[k - 1];
	}
};

// �������ѣ�Ȼ�󷵻����ѵ���С���������ڴ�������
// Runtime: 16 ms, faster than 53.60% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage : 10.8 MB, less than 9.85 % of C++ online submissions for Kth Largest Element in an Array.
class Solution2 {
private:
	typedef multiset<int> intSet;
	typedef multiset<int>::const_iterator setIterator;
public:
	int findKthLargest(vector<int>& nums, int k) {
		intSet greatestNumbers;
		auto iter = nums.cbegin();
		for (; iter != nums.cend(); ++iter) {
			if (greatestNumbers.size() < k) greatestNumbers.insert(*iter);
			else {
				setIterator iterLeast = greatestNumbers.cbegin();
				if (*iter > * iterLeast) {
					greatestNumbers.erase(iterLeast);
					greatestNumbers.insert(*iter);
				}
			}
		}
		return *greatestNumbers.cbegin();
	}
};

// leetcode by jianchao-li
// Runtime: 8 ms, faster than 98.09% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage : 9.1 MB, less than 90.76 % of C++ online submissions for Kth Largest Element in an Array.
class Solution3 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
		return nums[k - 1];
	}
};

// We may also use a heap to solve this problem.
// We can maintain the largest k elements in a heap with the smallest among them at the top.
// Or we can add all the elements to a heap,
// with the largest at the top,
// and then pop the heap for k - 1 times,
// then the one on the top is our target.
// The first one is min-heap and the second one is max-heap.
// In STL, both priority_queue and multiset can be used as a min/max-heap.

// min-heap using priority_queue
// Runtime: 12 ms, faster than 84.81% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage : 9.3 MB, less than 58.62 % of C++ online submissions for Kth Largest Element in an Array.
class Solution4 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int num : nums) {
			pq.push(num);
			if (pq.size() > k) {
				pq.pop();
			}
		}
		return pq.top();
	}
};

// leetcode by codeforlove
// ���ڿ��ţ�ƽ��ʱ�临�Ӷ�ΪO(n)
class Solution5 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		return findKthLargest(nums, 0, nums.size() - 1, k - 1);
	}

	int findKthLargest(vector<int>& nums, int head, int tail, int k)
	{
		int x = nums[head];
		int i = head;
		int j = tail;
		while (i < j)
		{
			while (i < j && nums[j] <= x)j--;
			nums[i] = nums[j];
			while (i < j && nums[i] >= x)i++;
			nums[j] = nums[i];
		}
		nums[i] = x;

		if (i == k)
			return nums[i];
		if (i < k)
			return findKthLargest(nums, i + 1, tail, k);
		if (i > k)
			return findKthLargest(nums, head, i - 1, k);
	}
};

//int main(int argc, char* argv[]) {
//	vector<int> nums = { 2,3,2,1,5,6,4,5 };
//	int ret = Solution4().findKthLargest(nums, 2);
//}