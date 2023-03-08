package org.wx.problems;

public class Solution0061 {

    //Definition for singly-linked list.
    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return head;
        }
        ListNode left = head;
        ListNode right = head;
        int len = 1;
        while (right.next != null) {
            len++;
            right = right.next;
        }
        k = k % len;
        k = len - k;
        for (int i = 1; i < k; i++) {
            left = left.next;
        }
        right.next = head;
        right = left.next;
        left.next = null;
        return right;
    }
}
