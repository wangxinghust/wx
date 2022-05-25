package org.wx.problems;

import java.util.ArrayList;
import java.util.List;

public class Solution0212 {
    public static class TrieNode {
        TrieNode[] next;
        String word;
        int refCnt;

        public TrieNode() {
            this.next = new TrieNode[26];
        }
    }

    int[][] dirs = new int[][]{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    TrieNode root;

    public List<String> findWords(char[][] board, String[] words) {
        root = new TrieNode();
        for (String word : words) {
            buildTree(word);
        }
        List<String> res = new ArrayList<>();
        int n = board.length;
        int m = board[0].length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (root.next[board[i][j] - 'a'] != null && root.next[board[i][j] - 'a'].refCnt > 0) {
                    dfs(board, i, j, root, res);
                }
            }
        }
        return res;
    }

    private void dfs(char[][] board, int i, int j, TrieNode cur, List<String> res) {
        if (i < 0 || i >= board.length
                || j < 0 || j >= board[0].length
                || board[i][j] == '@'
                || cur.next[board[i][j] - 'a'] == null || cur.next[board[i][j] - 'a'].refCnt == 0) {
            return;
        }
        cur = cur.next[board[i][j] - 'a'];
        if (cur != null && cur.word != null) {
            res.add(cur.word);
            // 剪枝，已确认可以生成的word可以从字典树中删去
            substract(cur.word);
            cur.word = null;
        }
        char temp = board[i][j];
        // 标记已访问过的二维数组字符
        board[i][j] = '@';
        for (int[] dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            dfs(board, x, y, cur, res);
        }
        board[i][j] = temp;
    }

    private void substract(String word) {
        TrieNode cur = root;
        for (int i = 0; i < word.length(); i++) {
            if (cur == null) {
                return;
            }
            if (cur.next[word.charAt(i) - 'a'] == null) {
                return;
            }
            cur.next[word.charAt(i) - 'a'].refCnt -= 1;
            if (cur.next[word.charAt(i) - 'a'].refCnt == 0) {
                cur.next[word.charAt(i) - 'a'] = null;
            }
            cur = cur.next[word.charAt(i) - 'a'];
        }
        if (cur != null && cur.refCnt == 0) {
            cur = null;
        }
    }

    private void buildTree(String word) {
        TrieNode cur = root;
        for (int i = 0; i < word.length(); i++) {
            if (cur.next[word.charAt(i) - 'a'] == null) {
                cur.next[word.charAt(i) - 'a'] = new TrieNode();
            }
            cur.next[word.charAt(i) - 'a'].refCnt += 1;
            cur = cur.next[word.charAt(i) - 'a'];
        }
        cur.word = word;
    }
}
