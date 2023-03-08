package org.wx.problems;

import java.util.*;

public class Solution0699 {
    // 有序集合
    // 思路和自己做错的比较类似，但是插入right节点时还要在right+1处再插入一个点，且直接使用treeMap，对坐标排序了。而不是链表
    // 再插入一个点的思路是记录点x，及x后高度均为y，也就是记录了所有的线段
    public List<Integer> fallingSquares3(int[][] positions) {
        int n = positions.length;
        List<Integer> ret = new ArrayList<Integer>();
        TreeMap<Integer, Integer> heightMap = new TreeMap<Integer, Integer>();
        heightMap.put(0, 0); // 初始时从 0 开始的所有点的堆叠高度都是 0
        for (int i = 0; i < n; i++) {
            int size = positions[i][1];
            int left = positions[i][0], right = positions[i][0] + positions[i][1] - 1;
            Integer lp = heightMap.higherKey(left), rp = heightMap.higherKey(right);
            Integer prevRightKey = rp != null ? heightMap.lowerKey(rp) : heightMap.lastKey();
            int rHeight = prevRightKey != null ? heightMap.get(prevRightKey) : 0; // 记录 right + 1 对应的堆叠高度（如果 right + 1 不在 heightMap 中）

            // 更新第 i 个掉落的方块的堆叠高度
            int height = 0;
            Integer prevLeftKey = lp != null ? heightMap.lowerKey(lp) : heightMap.lastKey();
            Map<Integer, Integer> tail = prevLeftKey != null ? heightMap.tailMap(prevLeftKey) : heightMap;
            for (Map.Entry<Integer, Integer> entry : tail.entrySet()) {
                if (entry.getKey() == rp) {
                    break;
                }
                height = Math.max(height, entry.getValue() + size);
            }

            // 清除 heightMap 中位于 (left, right] 内的点
            Set<Integer> keySet = new TreeSet<Integer>(tail.keySet());
            for (Integer tmp : keySet) {
                if (lp == null || tmp < lp) {
                    continue;
                }
                if (rp != null && tmp >= rp) {
                    break;
                }
                heightMap.remove(tmp);
            }

            heightMap.put(left, height); // 更新 left 的变化
            if (rp == null || rp != right + 1) { // 如果 right + 1 不在 heightMap 中，更新 right + 1 的变化
                heightMap.put(right + 1, rHeight);
            }
            ret.add(i > 0 ? Math.max(ret.get(i - 1), height) : height);
        }
        return ret;
    }

    // 这里-1太难理解，为了重叠判断写简单点而简单点，不确定特殊，left都是整数，所以可以-1
    public List<Integer> fallingSquares2(int[][] positions) {
        int n = positions.length;
        List<Integer> heights = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            int left1 = positions[i][0], right1 = positions[i][0] + positions[i][1];
            int height = positions[i][1];
            for (int j = 0; j < i; j++) {
                int left2 = positions[j][0], right2 = positions[j][0] + positions[j][1];
                // 重叠判断
                if (right1 >= left2 && right2 >= left1) {
                    height = Math.max(height, heights.get(j) + positions[i][1]);
                }
            }
            heights.add(height);
        }
        for (int i = 1; i < n; i++) {
            heights.set(i, Math.max(heights.get(i), heights.get(i - 1)));
        }
        return heights;
    }

    // 思路错误，点的高度不是单调增加或减少的，level求解是有问题的
    public class ListNode {
        int left;
        int height;
        //ListNode prev;
        ListNode next;

        ListNode() {

        }

        ListNode(int left, int height) {
            this.left = left;
            this.height = height;
        }
    }

    public List<Integer> fallingSquares(int[][] positions) {
        ListNode head = new ListNode(Integer.MIN_VALUE, 0);
        ListNode tail = new ListNode(Integer.MAX_VALUE, 0);
        head.next = tail;
        //tail.prev=head;
        int maxHeight = 0;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < positions.length; i++) {
            ListNode leftNode = addNode(head, positions[i][0], positions[i][1]);
            ListNode rightNode = addNode(head, positions[i][0] + positions[i][1], positions[i][1]);
            // 移除被覆盖节点
            leftNode.next = rightNode;
            //rightNode.prev=leftNode;
            int height = Math.max(leftNode.height, rightNode.height);
            leftNode.height = height;
            rightNode.height = height;
            maxHeight = Math.max(maxHeight, height);
            ans.add(maxHeight);
            printNode(head);
        }
        return ans;
    }

    private void printNode(ListNode head) {
        ListNode cur = head;
        while (cur != null) {
            System.out.println("[" + cur.left + "," + cur.height + "]");
            cur = cur.next;
        }
        System.out.println("---------");
    }

    private ListNode addNode(ListNode head, int left, int height) {
        ListNode node = null;
        ListNode cur = head;
        while (cur.next != null) {
            if (cur.next.left == left) {
                node = cur.next;
                int level = Math.min(cur.next.height, cur.next.next.height);
                node.height = level + height;
            } else if (cur.left < left && cur.next.left > left) {
                node = new ListNode(left, cur.next.height + height);
                // 插入
                ListNode temp = cur.next;
                cur.next = node;
                node.next = temp;
            }
            cur = cur.next;
        }
        return node;
    }

    public static void main(String[] args) {
        Solution0699 solution = new Solution0699();
        int[][] positions = new int[][]{{6, 1}, {9, 2}, {2, 4}};
        List<Integer> ans = solution.fallingSquares(positions);
        System.out.println(ans);
    }
}
