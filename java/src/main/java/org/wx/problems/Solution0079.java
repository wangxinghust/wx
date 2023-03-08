package org.wx.problems;

public class Solution0079 {
    public boolean exist(char[][] board, String word) {
        char[] chs = word.toCharArray();
        boolean[][] visit = new boolean[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == chs[0]) {
                    visit[i][j] = true;
                    if (exist(board, chs, visit, 1, i, j)) {
                        return true;
                    }
                    visit[i][j] = false;
                }
            }
        }
        return false;
    }

    private boolean exist(char[][] board, char[] chs, boolean[][] visit, int index, int row, int col) {
        if (index >= chs.length) {
            return true;
        }
        if (row != 0 && board[row - 1][col] == chs[index] && !visit[row - 1][col]) {
            visit[row - 1][col] = true;
            if (exist(board, chs, visit, index + 1, row - 1, col)) {
                return true;
            }
            visit[row - 1][col] = false;
        }
        if (row != board.length - 1 && board[row + 1][col] == chs[index] && !visit[row + 1][col]) {
            visit[row + 1][col] = true;
            if (exist(board, chs, visit, index + 1, row + 1, col)) {
                return true;
            }
            visit[row + 1][col] = false;
        }
        if (col != 0 && board[row][col - 1] == chs[index] && !visit[row][col - 1]) {
            visit[row][col - 1] = true;
            if (exist(board, chs, visit, index + 1, row, col - 1)) {
                return true;
            }
            visit[row][col - 1] = false;
        }
        if (col != board[0].length - 1 && board[row][col + 1] == chs[index] && !visit[row][col + 1]) {
            visit[row][col + 1] = true;
            if (exist(board, chs, visit, index + 1, row, col + 1)) {
                return true;
            }
            visit[row][col + 1] = false;
        }
        return false;
    }

    //dfs，写法优化
    public boolean exist2(char[][] board, String word) {
        boolean[][] visit = new boolean[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == word.charAt(0)) {
                    boolean res = dfs(board, visit, word, i, j, 0);
                    if (res) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, boolean[][] visit, String word, int i, int j, int idx) {
        if (idx == word.length()) {
            return true;
        }
        if (i >= 0 && i < board.length && j >= 0 && j < board[0].length && !visit[i][j] && board[i][j] == word.charAt(idx)) {
            visit[i][j] = true;
            boolean res = dfs(board, visit, word, i - 1, j, idx + 1)
                    || dfs(board, visit, word, i + 1, j, idx + 1)
                    || dfs(board, visit, word, i, j - 1, idx + 1)
                    || dfs(board, visit, word, i, j + 1, idx + 1);
            visit[i][j] = false;
            return res;
        }
        return false;
    }
}
