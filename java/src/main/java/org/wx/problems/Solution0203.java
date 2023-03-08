package org.wx.problems;

/**
 * @author Wang Xing
 * @date 8/5/21
 */
public class Solution0203 {
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(1);
        Solution0203 s = new Solution0203();
        s.removeElements(head, 1);
    }

    /**
     * Definition for singly-linked list.
     */
    static class ListNode {
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

    public ListNode removeElements(ListNode head, int val) {
        ListNode dummyHead = new ListNode();
        dummyHead.next = head;
        ListNode last = dummyHead;
        ListNode cur = head;
        while (cur != null) {
            if (cur.val == val) {
                last.next = cur.next;
                cur = cur.next;
                continue;
            }
            last = last.next;
            cur = cur.next;
        }
        return dummyHead.next;
    }

    /**
     * leetcode by lx223
     * 优化if-else
     */
    public ListNode removeElements2(ListNode head, int val) {
        ListNode dummyHead = new ListNode();
        dummyHead.next = head;
        ListNode last = dummyHead;
        ListNode cur = head;
        while (cur != null) {
            if (cur.val == val) {
                last.next = cur.next;
            } else {
                last = last.next;
            }
            cur = cur.next;
        }
        return dummyHead.next;
    }

    /**
     * leetcode by mscho147
     * 双指针改单指针，降低内存占用
     */
    public ListNode removeElements3(ListNode head, int val) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode cur = dummy;

        while (cur.next != null) {
            if (cur.next.val == val) {
                cur.next = cur.next.next;
            } else {
                cur = cur.next;
            }
        }
        return dummy.next;
    }
}
