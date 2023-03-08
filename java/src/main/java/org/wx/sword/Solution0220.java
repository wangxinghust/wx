package org.wx.sword;

public class Solution0220 {

    //Definition for singly-linked list.
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode first = head;
        while (k > 0) {
            first = first.next;
            k--;
        }
        ListNode second = head;
        while (first != null) {
            first = first.next;
            second = second.next;
        }
        return second;
    }
}
