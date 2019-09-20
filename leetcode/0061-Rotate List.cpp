#include <cstddef>

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//思路：遍历到倒数第k+1个，
	//Runtime: 8 ms, faster than 94.78% of C++ online submissions for Rotate List.
	//Memory Usage : 8.9 MB, less than 71.34 % of C++ online submissions for Rotate List.
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL) return head;
		ListNode* pFirst = head, * pSecond = head;
		for (int i = 0; i < k; ++i) {
			pFirst = pFirst->next;
			//如果遍历到链表末尾处
			if (pFirst == NULL) { 
				pFirst = head;
				//针对k极大情况进行优化，避免反复遍历，造成Time Limit Exceeded
				k %= (i + 1);
				//循环掉k%(i+1)的量
				for (int j = 0; j < k; ++j) {
					pFirst = pFirst->next;
				}
				//跳出外层循环
				break;
			}
		}

		//如果回到了头结点，也就是右旋回到了初始状态
		if (pFirst == head) return head;

		while (pFirst->next != NULL) {
			pFirst = pFirst->next;
			pSecond = pSecond->next;
		}

		//暂存新的头结点
		ListNode* newHead = pSecond->next;

		//断开链接
		pSecond->next = NULL;

		//重新链接
		pFirst->next = head;

		return newHead;
	}
};