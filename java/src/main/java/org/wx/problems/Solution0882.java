package org.wx.problems;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class Solution0882 {
    private static class ANode {
        int node, dist;

        ANode(int n, int d) {
            node = n;
            dist = d;
        }
    }

    /**
     * 邻接表方案，重点在于应用Dijkstra算法时同时记录下每条边所使用的权值，可以看代码中used这个Map的奇妙用法
     */
    public int reachableNodes(int[][] edges, int maxMoves, int n) {
        Map<Integer, Map<Integer, Integer>> graph = new HashMap<>();
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph.computeIfAbsent(u, x -> new HashMap<>()).put(v, w);
            graph.computeIfAbsent(v, x -> new HashMap<>()).put(u, w);
        }

        PriorityQueue<ANode> pq = new PriorityQueue<ANode>(
                (a, b) -> Integer.compare(a.dist, b.dist));
        pq.offer(new ANode(0, 0));

        Map<Integer, Integer> dist = new HashMap<>();
        dist.put(0, 0);
        Map<Integer, Integer> used = new HashMap<>();
        int ans = 0;

        while (!pq.isEmpty()) {
            ANode anode = pq.poll();
            int node = anode.node;
            int d = anode.dist;

            if (d > dist.getOrDefault(node, 0)) continue;
            // Each node is only visited once.  We've reached
            // a node in our original graph.
            ans++;

            if (!graph.containsKey(node)) continue;
            for (int nei : graph.get(node).keySet()) {
                // maxMoves - d is how much further we can walk from this node;
                // weight is how many new nodes there are on this edge.
                // v is the maximum utilization of this edge.
                int weight = graph.get(node).get(nei);
                int v = Math.min(weight, maxMoves - d);
                used.put(n * node + nei, v);

                // d2 is the total distance to reach 'nei' (neighbor) node
                // in the original graph.
                int d2 = d + weight + 1;
                if (d2 < dist.getOrDefault(nei, maxMoves + 1)) {
                    pq.offer(new ANode(nei, d2));
                    dist.put(nei, d2);
                }
            }
        }

        // At the end, each edge (u, v, w) can be used with a maximum
        // of w new nodes: a max of used[u, v] nodes from one side,
        // and used[v, u] nodes from the other.
        // [We use the encoding (u, v) = u * n + v.]
        for (int[] edge : edges) {
            ans += Math.min(edge[2], used.getOrDefault(edge[0] * n + edge[1], 0) +
                    used.getOrDefault(edge[1] * n + edge[0], 0));
        }

        return ans;
    }

    /**
     * 邻接矩阵方案
     */
    public int reachableNodes2(int[][] edges, int maxMoves, int n) {
        // 邻接矩阵
        int[][] graph = new int[n][n];
        // 初始化邻接矩阵
        for (int[] edge : edges) {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
        // TODO: 9/12/21 补充邻接矩阵方案
        int ans = 0;
        return ans;
    }
}
