package org.wx.interview;

public class Solution1711 {
    public int findClosest(String[] words, String word1, String word2) {
        int length = words.length;
        int indexWord1 = -1, indexWord2 = -1;
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < length; i++) {
            if (words[i].equals(word1)) {
                indexWord1 = i;
            } else if (words[i].equals(word2)) {
                indexWord2 = i;
            }
            if (indexWord1 > -1 && indexWord2 > -1) {
                //int abs=indexWord1>indexWord2?indexWord1-indexWord2:indexWord2-indexWord1;
                ans = Math.min(ans, Math.abs(indexWord1 - indexWord2));
            }
        }
        return ans;
    }
}
