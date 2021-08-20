package org.wx.problems;

import java.util.HashSet;
import java.util.Set;

public class Solution0036 {

    public static void main(String[] args) {
        Solution0036 solution = new Solution0036();
        char[][] board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        boolean isSudoku = solution.isValidSudoku(board);
        System.out.println(isSudoku);
    }

    /**
     * 36. Valid Sudoku
     * HashSet可升级为Bitmasking
     * x & (1 << i)
     */
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            Set<Character> row = new HashSet<>(), col = new HashSet<>();
            for (int j = 0; j < 9; j++) {
                if ((board[i][j] != '.' && row.contains(board[i][j])) || (board[j][i] != '.' && col.contains(board[j][i]))) {
                    return false;
                }
                row.add(board[i][j]);
                col.add(board[j][i]);
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                Set<Character> box = new HashSet<>();
                for (int m = 0; m < 3; m++) {
                    for (int n = 0; n < 3; n++) {
                        if (board[i + m][j + n] != '.' && box.contains(board[i + m][j + n])) {
                            return false;
                        }
                        box.add(board[i + m][j + n]);
                    }
                }
            }
        }
        return true;
    }
}
