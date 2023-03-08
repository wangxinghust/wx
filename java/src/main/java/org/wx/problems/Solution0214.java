package org.wx.problems;

/**
 * @author Wang Xing
 * @date 8/7/21
 */
public class Solution0214 {
    public static void main(String[] args) {
        Solution0214 solution = new Solution0214();
        String result = solution.shortestPalindrome2("aacecaaa");
        System.out.println(result);
    }

    /**
     * 214. Shortest Palindrome
     * 2021-8-7 13:56:53
     * <p>
     * 超时
     */
    public String shortestPalindrome(String s) {
        if (s.length() <= 1) {
            return s;
        }
        int max = 1;
        for (int i = 0; i < s.length(); i++) {
            if (isPalindrome(s, i)) max = i + 1;
        }
        StringBuilder result = new StringBuilder();
        for (int i = s.length() - 1; i >= max; i--) {
            result.append(s.charAt(i));
        }
        return result.append(s).toString();
    }

    private boolean isPalindrome(String s, int right) {
        int i = 0, j = right;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    public String shortestPalindrome2(String s) {
        if (s.length() <= 1) {
            return s;
        }

        int index = s.length() - 1;
        boolean isMax = false;
        while (!isMax) {
            int left = 0, right = index;
            boolean isPalindrome = true;
            while (left < right) {
                if (s.charAt(left) != s.charAt(right)) {
                    isPalindrome = false;
                    break;
                }
                left++;
                right--;
            }
            if (isPalindrome) {
                isMax = true;
            }
            index--;
        }
        index++;
//        StringBuilder result = new StringBuilder();
//        for (int i = s.length() - 1; i > index; i--) {
//            result.append(s.charAt(i));
//        }
//        return result.append(s).toString();
        // 效率没什么改变，但写法好看点
        return new StringBuilder(s.substring(index + 1)).reverse().append(s).toString();
    }

    // 官方暴力解法1 找最大从0开始的回文，最快方式是反转后和原串比较
}
