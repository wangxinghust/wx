package org.wx.problems;

/**
 * 1189. Maximum Number of Balloons
 */
public class Solution1189 {
    public int maxNumberOfBalloons(String text) {
        char[] letters = text.toCharArray();
        int[] count = new int[5];
        for (char letter : letters) {
            switch (letter) {
                case 'a':
                    count[0]++;
                    break;
                case 'b':
                    count[1]++;
                    break;
                case 'l':
                    count[2]++;
                    break;
                case 'o':
                    count[3]++;
                    break;
                case 'n':
                    count[4]++;
                    break;
                default:
            }
        }
        int ans = Math.min(count[0], count[1]);
        ans = Math.min(ans, count[2] >>> 1);
        ans = Math.min(ans, count[3] >>> 1);
        ans = Math.min(ans, count[4]);
        return ans;
    }
}
