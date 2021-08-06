package org.wx.problems;

import java.util.ArrayList;
import java.util.List;

// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {
    }

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
}

/**
 * @author Wang Xing
 * @date 8/6/21
 */
public class Solution0429 {
    /**
     * 429. N-ary Tree Level Order Traversal
     * 2021-8-6 23:32:06
     */
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) {
            return result;
        }

        List<Node> row = new ArrayList<>();
        row.add(root);
        while (row.size() > 0) {
            List<Node> copy = new ArrayList<>();
            List<Integer> num = new ArrayList<>();
            for (Node node : row) {
                num.add(node.val);
                copy.addAll(node.children);
            }
            result.add(num);
            row = copy;
        }
        return result;
    }
}
