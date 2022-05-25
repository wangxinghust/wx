package org.wx.problems;

public class Solution0165 {
    public int compareVersion(String version1, String version2) {
        String[] str1 = version1.split("\\.");
        String[] str2 = version2.split("\\.");
        if (str1.length <= str2.length) {
            return compareVersion(str1, str2);
        } else {
            return -compareVersion(str2, str1);
        }
    }

    private int compareVersion(String[] str1, String[] str2) {
        int i = 0;
        int m = str1.length, n = str2.length;
        for (; i < m; i++) {
            int x = Integer.parseInt(str1[i]);
            int y = Integer.parseInt(str2[i]);
            if (x != y) {
                return x < y ? -1 : 1;
            }
        }
        for (; i < n; i++) {
            int y = Integer.parseInt(str2[i]);
            if (y != 0) {
                return 0 < y ? -1 : 1;
            }
        }
        return 0;
    }

    public int compareVersion2(String version1, String version2) {
        int i = 0, j = 0, n1 = version1.length(), n2 = version2.length(), num1 = 0, num2 = 0;
        while (i < n1 || j < n2) {
            while (i < n1 && version1.charAt(i) != '.') {
                num1 = num1 * 10 + (version1.charAt(i) - '0');
                i++;
            }
            while (j < n2 && version2.charAt(j) != '.') {
                num2 = num2 * 10 + (version2.charAt(j) - '0');
                j++;
            }
            if (num1 > num2) {
                return 1;
            }
            if (num1 < num2) {
                return -1;
            }
            i++;
            j++;
            num1 = 0;
            num2 = 0;
        }
        return 0;
    }
}
