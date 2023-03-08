package org.wx.problems;

/**
 * 1275. Find Winner on a Tic Tac Toe Game
 */
public class Solution1275 {
    public String tictactoe(int[][] moves) {
        char[][] grid = new char[3][3];
        for (int i = 0; i < moves.length; i++) {
            grid[moves[i][0]][moves[i][1]] = i % 2 == 0 ? 'X' : 'O';
        }
        if (isWin('X', grid)) {
            return "A";
        }
        if (isWin('O', grid)) {
            return "B";
        }
        if (moves.length == 9) {
            return "Draw";
        } else {
            return "Pending";
        }
    }

    private boolean isWin(char ch, char[][] grid) {
        // 行
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == ch && grid[i][1] == ch && grid[i][2] == ch) {
                return true;
            }
        }
        // 列
        for (int j = 0; j < 3; j++) {
            if (grid[0][j] == ch && grid[1][j] == ch && grid[2][j] == ch) {
                return true;
            }
        }
        // 斜对角
        if (grid[1][1] == ch) {
            if (grid[0][0] == ch && grid[2][2] == ch) {
                return true;
            }
            if (grid[0][2] == ch && grid[2][0] == ch) {
                return true;
            }
        }
        return false;
    }

    /**
     * 官方解答2 通过降维记录 削减空间复杂度 可应对 n x n 问题
     */
    public String tictactoe2(int[][] moves) {

        // n stands for the size of the board, n = 3 for the current game.
        int n = 3;

        // Use rows and cols to record the value on each row and each column.
        // diag1 and diag2 to record value on diagonal or anti-diagonal.
        int[] rows = new int[n], cols = new int[n];
        int diag = 0, anti_diag = 0;

        // Two players having value of 1 and -1, player_1 with value = 1 places first.
        int player = 1;

        for (int[] move : moves) {

            // Get the row number and column number for this move.
            int row = move[0], col = move[1];

            // Update the row value and column value.
            rows[row] += player;
            cols[col] += player;

            // If this move is placed on diagonal or anti-diagonal,
            // we shall update the relative value as well.
            if (row == col) {
                diag += player;
            }
            if (row + col == n - 1) {
                anti_diag += player;
            }

            // Check if this move meets any of the winning conditions.
            if (Math.abs(rows[row]) == n || Math.abs(cols[col]) == n ||
                    Math.abs(diag) == n || Math.abs(anti_diag) == n) {
                return player == 1 ? "A" : "B";
            }

            // If no one wins so far, change to the other player alternatively.
            // That is from 1 to -1, from -1 to 1.
            player *= -1;
        }

        // If all moves are completed and there is still no result, we shall check if
        // the grid is full or not. If so, the game ends with draw, otherwise pending.
        return moves.length == n * n ? "Draw" : "Pending";
    }
}
