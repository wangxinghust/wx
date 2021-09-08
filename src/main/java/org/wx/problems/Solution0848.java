package org.wx.problems;

/**
 * 848. Shifting Letters
 */
public class Solution0848 {
    public static void main(String[] args) {
        Solution0848 solution = new Solution0848();
        String ans = solution.shiftingLetters("mkgfzkkuxownxvfvxasy", new int[]{505870226, 437526072, 266740649, 224336793, 532917782, 311122363, 567754492, 595798950, 81520022, 684110326, 137742843, 275267355, 856903962, 148291585, 919054234, 467541837, 622939912, 116899933, 983296461, 536563513});
        System.out.println(ans);
    }

    /**
     * 循环可以合并，可以建临时变量来替代此处shifts数组的作用
     */
    public String shiftingLetters(String s, int[] shifts) {
        for (int i = shifts.length - 2; i >= 0; i--) {
            // 考虑shifts[i]的范围
            shifts[i] = shifts[i] % 26 + shifts[i + 1] % 26;
        }
        char[] chs = s.toCharArray();
        for (int i = 0; i < chs.length; i++) {
            chs[i] = (char) ((chs[i] - 'a' + shifts[i]) % 26 + 'a');
        }
        return new String(chs);
    }
}
