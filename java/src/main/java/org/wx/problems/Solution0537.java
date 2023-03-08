package org.wx.problems;

/**
 * 537. Complex Number Multiplication
 */
public class Solution0537 {
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    public static void main(String[] args) {
        Solution0537 solution = new Solution0537();
        String res = solution.complexNumberMultiply("1+-1i", "1+-1i");
        System.out.println(res);
    }

    public String complexNumberMultiply(String num1, String num2) {
        strToNum(num1, num2);
        int x = x1 * x2 - y1 * y2;
        int y = x1 * y2 + x2 * y1;
        return String.valueOf(x) + "+" + String.valueOf(y) + "i";
    }

    private void strToNum(String num1, String num2) {
        int index = num1.indexOf('+');
        x1 = Integer.parseInt(num1.substring(0, index));
        y1 = Integer.parseInt(num1.substring(index + 1, num1.length() - 1));
        index = num2.indexOf('+');
        x2 = Integer.parseInt(num2.substring(0, index));
        y2 = Integer.parseInt(num2.substring(index + 1, num2.length() - 1));
    }
}
