#include <vector>
using namespace std;

// Approach #1 Sorting

// Approach #2 Set

// Approach #3 Floyd's Tortoise and Hare (Cycle Detection)
// 
// ���ַ�ΧΪ1��n��nums[i]����ָ����������һ���㣬Ҳ���ǰ����鵱�����������е�ֵ����next
// ����������ÿ���㶼��ָ����ڵĵ㣬��˿������ޱ�����Ҳ���ǳɻ�
// ������0��nums[0]һ���ڻ��⣬��Ϊnums[0]����Ϊ�������
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