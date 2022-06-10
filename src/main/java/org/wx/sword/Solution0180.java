package org.wx.sword;

public class Solution0180 {

    //Definition for singly-linked list.
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public ListNode deleteNode(ListNode head, int val) {
        if (head.val == val) {
            return head.next;
        }
        ListNode node = head;
        while (node != null && node.next != null) {
            if (node.next.val == val) {
                node.next = node.next.next;
            }
            node = node.next;
        }
        return head;
    }
}
