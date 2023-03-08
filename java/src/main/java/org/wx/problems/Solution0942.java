package org.wx.problems;

public class Solution0942 {
    // 类似桶排序，先比大小排好，再计算相同数个数，累和后直接得出该数位置，每访问一个，累计和减1
    public int[] diStringMatch(String s) {
        int[] perm = new int[s.length() + 1];
        int minNum = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == 'I') {
                perm[i + 1] = perm[i] + 1;
            } else {
                perm[i + 1] = perm[i] - 1;
            }
            minNum = Math.min(perm[i + 1], minNum);
        }
        int[] sum = new int[perm.length];
        for (int i = 0; i < perm.length; i++) {
            perm[i] = perm[i] - minNum;
            sum[perm[i]]++;
        }
        //System.out.println(Arrays.toString(perm));
        for (int i = 1; i < sum.length; i++) {
            sum[i] += sum[i - 1];
        }
        //System.out.println(Arrays.toString(sum));
        for (int i = 0; i < perm.length; i++) {
            perm[i] = --sum[perm[i]];
        }
        return perm;
    }

    // 此法依据是小于则取最小，一定满足。最小值和最大值类似游标移动。因为string有长度，因此数字上限high已知
    public int[] diStringMatch2(String s) {
        int len = s.length(), low = 0, high = len;
        int[] perm = new int[len + 1];
        for (int i = 0; i < len; i++) {
            perm[i] = 'I' == s.charAt(i) ? low++ : high--;
        }
        perm[len] = low;
        return perm;
    }
}
