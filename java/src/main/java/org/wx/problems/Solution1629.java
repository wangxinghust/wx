package org.wx.problems;

/**
 * 1629. Slowest Key
 */
public class Solution1629 {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        int[] times = new int[26];
        char[] pressed = keysPressed.toCharArray();
        for (int i = 0; i < pressed.length; i++) {
            times[pressed[i] - 'a'] = Math.max(times[pressed[i] - 'a'], releaseTimes[i] - (i == 0 ? 0 : releaseTimes[i - 1]));
        }
        int maxTime = 0;
        char ans = pressed[0];
        for (int i = 0; i < 26; i++) {
            if (times[i] >= maxTime) {
                ans = (char) ('a' + i);
                maxTime = times[i];
            }
        }
        return ans;
    }
}
