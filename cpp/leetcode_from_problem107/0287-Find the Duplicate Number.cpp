#include <vector>
using namespace std;

// Approach #1 Sorting

// Approach #2 Set

// Approach #3 Floyd's Tortoise and Hare (Cycle Detection)
// 
// 数字范围为1到n，nums[i]可以指向数组中另一个点，也就是把数组当做链表，数组中的值当做next
// 由于数组里每个点都能指向存在的点，因此可以无限遍历，也就是成环
// 不存在0，nums[0]一定在环外，因为nums[0]可作为遍历起点
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int tortoise = nums[0];
		int hare = nums[0];
		do {
			tortoise = nums[tortoise];
			hare = nums[nums[hare]];
		} while (tortoise != hare);

		// find the "entrance" to the cycle
		int ptr1 = nums[0];
		int ptr2 = tortoise;
		while (ptr1 != ptr2) {
			ptr1 = nums[ptr1];
			ptr2 = nums[ptr2];
		}

		return ptr1;
	}
};