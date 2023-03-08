package org.wx.sword;

public class Solution0120 {
    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == word.charAt(0)) {
                    boolean res = dfs(board, word, 0, i, j);
                    if (res) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, String word, int index, int row, int col) {
        if (index >= word.length()) {
            return true;
        }
        if (row < 0 || row >= board.length || col < 0 || col >= board[0].length || board[row][col] != word.charAt(index)) {
            return false;
        }
        int[][] direct = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        if (board[row][col] == word.charAt(index)) {
            char tmp = board[row][col];
            board[row][col] = '@';
            boolean res = dfs(board, word, index + 1, row + direct[0][0], col + direct[0][1])
                    || dfs(board, word, index + 1, row + direct[1][0], col + direct[1][1])
                    || dfs(board, word, index + 1, row + direct[2][0], col + direct[2][1])
                    || dfs(board, word, index + 1, row + direct[3][0], col + direct[3][1]);
            board[row][col] = tmp;
            return res;
        }
        return false;
    }
}
