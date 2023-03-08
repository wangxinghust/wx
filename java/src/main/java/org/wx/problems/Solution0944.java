package org.wx.problems;

public class Solution0944 {
    public int minDeletionSize(String[] strs) {
        int deleteColNum = 0;
        int rowNum = strs.length;
        int colNum = strs[0].length();
        for (int i = 0; i < colNum; i++) {
            for (int j = 1; j < rowNum; j++) {
                if (strs[j].charAt(i) - strs[j - 1].charAt(i) < 0) {
                    deleteColNum++;
                    break;
                }
            }
        }
        return deleteColNum;
    }
}
