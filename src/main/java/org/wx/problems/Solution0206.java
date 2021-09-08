package org.wx.problems;

public class Solution0206 {
    // Definition for singly-linked list.
    public static class ListNode {
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

    /**
     * next是临时变量，可以挪入到内层 代码会更简洁点
     */
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode prev = null;
        ListNode node = head;
        ListNode next = head.next;
        while (next != null) {
            node.next = prev;
            prev = node;
            node = next;
            next = next.next;
        }
        node.next = prev;
        return node;
    }
}
