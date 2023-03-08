package org.wx.problems;

public class Solution0037 {
    public static void main(String[] args) {
        Solution0037 solution = new Solution0037();
        char[][] board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        printChar(board);
        solution.solveSudoku(board);
        printChar(board);
    }

    /**
     * 37. Sudoku Solver
     * 暴力遍历 dfs+行列校验 校验采用bitMap，
     * 可以仅检查此行此列此小格是否出现过该值即可，无需校验有效性
     */
    private static void printChar(char[][] board) {
        System.out.println("-----------------");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(board[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }
    }

    public void solveSudoku(char[][] board) {
        dfs(board);
    }

    private boolean dfs(char[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; k++) {
                        board[i][j] = (char) ('0' + k);
                        if (isValid(board, i, j)) {
                            if (dfs(board)) {
                                return true;
                            }
                        }
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }

    private boolean isValid(char[][] board, int row, int col) {
        int hash = 0;
        for (int i = 0; i < 9; i++) {
            if (board[row][i] != '.') {
                if ((hash & (1 << (board[row][i] - '0'))) != 0) {
                    return false;
                }
                hash = hash | (1 << (board[row][i] - '0'));
            }
        }
        hash = 0;
        for (int i = 0; i < 9; i++) {
            if (board[i][col] != '.') {
                if ((hash & (1 << board[i][col] - '0')) != 0) {
                    return false;
                }
                hash = hash | (1 << (board[i][col] - '0'));
            }
        }
        hash = 0;
        for (int m = 0; m < 3; m++) {
            for (int n = 0; n < 3; n++) {
                if (board[m + row / 3 * 3][n + col / 3 * 3] != '.') {
                    if ((hash & (1 << board[m + row / 3 * 3][n + col / 3 * 3] - '0')) != 0) {
                        return false;
                    }
                    hash = hash | (1 << (board[m + row / 3 * 3][n + col / 3 * 3] - '0'));
                }
            }
        }
        return true;
    }
}
