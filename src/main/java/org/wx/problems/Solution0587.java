package org.wx.problems;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Stack;

/**
 * 587. Erect the Fence
 */
public class Solution0587 {
    /**
     * Approach 1: Jarvis Algorithm
     */
    public int[][] outerTrees(int[][] trees) {
        HashSet<int[]> hull = new HashSet<>();
        if (trees.length < 4) {
            for (int[] p : trees)
                hull.add(p);
            return hull.toArray(new int[hull.size()][]);
        }
        int left_most = 0;
        for (int i = 0; i < trees.length; i++)
            if (trees[i][0] < trees[left_most][0])
                left_most = i;
        int p = left_most;
        do {
            int q = (p + 1) % trees.length;
            for (int i = 0; i < trees.length; i++) {
                if (orientation(trees[p], trees[i], trees[q]) < 0) {
                    q = i;
                }
            }
            for (int i = 0; i < trees.length; i++) {
                if (i != p && i != q && orientation(trees[p], trees[i], trees[q]) == 0 && inBetween(trees[p], trees[i], trees[q])) {
                    hull.add(trees[i]);
                }
            }
            hull.add(trees[q]);
            p = q;
        }
        while (p != left_most);
        return hull.toArray(new int[hull.size()][]);
    }

    private int orientation(int[] p, int[] q, int[] r) {
        return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    }

    private boolean inBetween(int[] p, int[] i, int[] q) {
        boolean a = i[0] >= p[0] && i[0] <= q[0] || i[0] <= p[0] && i[0] >= q[0];
        boolean b = i[1] >= p[1] && i[1] <= q[1] || i[1] <= p[1] && i[1] >= q[1];
        return a && b;
    }

    /**
     * Approach 2: Graham Scan
     */
    public int[][] outerTrees2(int[][] trees) {
        if (trees.length <= 1)
            return trees;
        int[] bm = bottomLeft(trees);
        Arrays.sort(trees, new Comparator<int[]>() {
            public int compare(int[] p, int[] q) {
                double diff = orientation(bm, p, q) - orientation(bm, q, p);
                if (diff == 0)
                    return distance(bm, p) - distance(bm, q);
                else
                    return diff > 0 ? 1 : -1;
            }
        });
        int i = trees.length - 1;
        while (i >= 0 && orientation(bm, trees[trees.length - 1], trees[i]) == 0)
            i--;
        for (int l = i + 1, h = trees.length - 1; l < h; l++, h--) {
            int[] temp = trees[l];
            trees[l] = trees[h];
            trees[h] = temp;
        }
        Stack<int[]> stack = new Stack<>();
        stack.push(trees[0]);
        stack.push(trees[1]);
        for (int j = 2; j < trees.length; j++) {
            int[] top = stack.pop();
            while (orientation(stack.peek(), top, trees[j]) > 0)
                top = stack.pop();
            stack.push(top);
            stack.push(trees[j]);
        }
        return stack.toArray(new int[stack.size()][]);
    }

    private int distance(int[] p, int[] q) {
        return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }

    private static int[] bottomLeft(int[][] points) {
        int[] bottomLeft = points[0];
        for (int[] p : points)
            if (p[1] < bottomLeft[1])
                bottomLeft = p;
        return bottomLeft;
    }

    /**
     * Approach 3: Monotone Chain
     */
    public int[][] outerTrees3(int[][] trees) {
        Arrays.sort(trees, new Comparator<int[]>() {
            public int compare(int[] p, int[] q) {
                return q[0] - p[0] == 0 ? q[1] - p[1] : q[0] - p[0];
            }
        });
        Stack<int[]> hull = new Stack<>();
        for (int i = 0; i < trees.length; i++) {
            while (hull.size() >= 2 && orientation(hull.get(hull.size() - 2), hull.get(hull.size() - 1), trees[i]) > 0)
                hull.pop();
            hull.push(trees[i]);
        }
        hull.pop();
        for (int i = trees.length - 1; i >= 0; i--) {
            while (hull.size() >= 2 && orientation(hull.get(hull.size() - 2), hull.get(hull.size() - 1), trees[i]) > 0)
                hull.pop();
            hull.push(trees[i]);
        }
        // remove redundant elements from the stack
        HashSet<int[]> ret = new HashSet<>(hull);
        return ret.toArray(new int[ret.size()][]);
    }
}
