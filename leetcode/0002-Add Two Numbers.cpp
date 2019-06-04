#include <cstdlib>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//There actually change the value of the chain l1 or l2, so there is no need to create the l3 if the value of the l1&l2 can be changed
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *l3=new ListNode(l1->val + l2->val);
		ListNode *pHead = l3;
		l1 = l1->next;
		l2 = l2->next;
		while (l1 != NULL || l2 != NULL)
		{
			if (l1 == NULL)
			{
				l3->next = l2;
				break;
			}
			if (l2 == NULL)
			{
				l3->next = l1;
				break;
			}
			ListNode *tmp = new ListNode(l1->val + l2->val);
			l3->next = tmp;
			l3 = l3->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		//traverse the carry, there is no need to recursive;
		l3 = pHead;
		while (l3)
		{
			if (l3->val >= 10)
			{
				l3->val -= 10;
				if (l3->next)
				{
					l3->next->val += 1;
				}
				else
				{
					//ListNode *tmp;
					//tmp->val = 1;
					//the null pointer created by an error in the original solution cannot be accessed
					ListNode *tmp = new ListNode(1);
					l3->next = tmp;
					break;
				}
			}
			l3 = l3->next;
		}
		return pHead;
	}
};