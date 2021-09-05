package org.wx.problems;

import java.util.*;

/**
 * 834. Sum of Distances in Tree
 */
public class Solution0834 {
    public static void main(String[] args) {
        Solution0834 solution = new Solution0834();
        int[] sum = solution.sumOfDistancesInTree2(2, new int[][]{{1, 0}});
        System.out.println(Arrays.toString(sum));
    }

    public int[] sumOfDistancesInTree(int n, int[][] edges) {
//        Arrays.sort(edges, (edge1, edge2) -> {
//            if (edge1[0] == edge2[0]) {
//                return edge1[1] - edge2[1];
//            }
//            return edge1[0] - edge2[0];
//        });

        int[][] len = new int[n][n];
        for (int[] edge : edges) {
            len[edge[0]][edge[1]] = 1;
            len[edge[1]][edge[0]] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (len[i][j] != 0) {
                    continue;
                }
                for (int k = 0; k < i; k++) {
                    if (len[k][j] != 0) {
                        if (len[i][j] == 0) {
                            len[i][j] = len[k][i] + len[k][j];
                        } else {
                            len[i][j] = Math.min(len[i][j], len[k][i] + len[k][j]);
                        }
                    }
                }
                for (int k = i + 1; k < j; k++) {
                    if (len[k][j] != 0) {
                        if (len[i][j] == 0) {
                            len[i][j] = len[i][k] + len[k][j];
                        } else {
                            len[i][j] = Math.min(len[i][j], len[i][k] + len[k][j]);
                        }
                    }
                }
            }
        }
        int[] sum = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                sum[i] += len[j][i];
            }
            for (int j = i + 1; j < n; j++) {
                sum[i] += len[i][j];
            }
        }
        return sum;
    }

    int[] ans, count;
    // 邻接表
    List<Set<Integer>> graph;
    int N;

    /**
     * 方法一：树形动态规划
     * https://leetcode-cn.com/problems/sum-of-distances-in-tree/solution/shu-zhong-ju-chi-zhi-he-by-leetcode-solution/
     */
    public int[] sumOfDistancesInTree2(int n, int[][] edges) {
        this.N = n;
        graph = new ArrayList<Set<Integer>>();
        ans = new int[n];
        count = new int[n];
        Arrays.fill(count, 1);

        for (int i = 0; i < n; ++i)
            graph.add(new HashSet<Integer>());
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }

    public void dfs(int node, int parent) {
        for (int child : graph.get(node))
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
    }

    public void dfs2(int node, int parent) {
        for (int child : graph.get(node))
            if (child != parent) {
                ans[child] = ans[node] - count[child] + N - count[child];
                dfs2(child, node);
            }
    }
}
