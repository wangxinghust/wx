package org.wx.sword;

public class Solution0240 {

    //Definition for singly-linked list.
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return head;
        }
        ListNode first = head;
        ListNode second = null;
        while (first != null) {
            ListNode tmp = first.next;
            first.next = second;
            second = first;
            first = tmp;
        }
        return second;
    }

}
