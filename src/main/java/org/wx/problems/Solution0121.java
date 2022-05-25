package org.wx.problems;

public class Solution0121 {
    public int maxProfit(int[] prices) {
        int min = prices[0];
        int res = 0;
        for (int i = 1; i < prices.length; i++) {
            //min=prices[i]<min?prices[i]:min;
            min = Math.min(prices[i], min);
            res = Math.max(res, prices[i] - min);
        }
        return res;
    }

    public int maxProfit2(int[] prices) {
        int lsf = Integer.MAX_VALUE;
        int op = 0;
        int pist = 0;

        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < lsf) {
                lsf = prices[i];
            }
            pist = prices[i] - lsf;
            if (op < pist) {
                op = pist;
            }
        }
        return op;
    }
}
