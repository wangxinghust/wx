package org.wx.problems;

/**
 * 917. Reverse Only Letters
 */
public class Solution0917 {
    public static void main(String[] args) {
        Solution0917 solution = new Solution0917();
        String ans = solution.reverseOnlyLetters("ab-cd");
        System.out.println(ans);
    }

    public String reverseOnlyLetters(String s) {
        char[] chs = s.toCharArray();
        int left = 0, right = chs.length - 1;
        do {
            while (left < right && !Character.isAlphabetic(chs[left])) {
                left++;
            }
            while (left < right && !Character.isAlphabetic(chs[right])) {
                right--;
            }
            if (left >= right) {
                break;
            }
            char temp = chs[left];
            chs[left] = chs[right];
            chs[right] = temp;
            left++;
            right--;
        } while (left < right);
        return new String(chs);
    }
}
