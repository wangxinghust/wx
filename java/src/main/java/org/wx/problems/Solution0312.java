package org.wx.problems;

/**
 * 312. 戳气球
 */
public class Solution0312 {
    //方法二：动态规划
    // 反向思考，从戳气球变成加气球
    // dp[i][j] 表示填满开区间(i,j) 能得到的最多硬币数
    // dp[i][j]=max( val[i]×val[k]×val[j]+dp[i][k]+dp[k][j] )，k从i+1到j-1，i<j−1
    // dp[i][j]=0 当i>=j−1
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[][] rec = new int[n + 2][n + 2];
        // 首尾补充1，便于计算
        int[] val = new int[n + 2];
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i - 1];
        }
        // 遍历顺序是从中间往两边扩展，因为最终要的值是rec[0][n + 1]
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j <= n + 1; j++) {
                for (int k = i + 1; k < j; k++) {
                    int sum = val[i] * val[k] * val[j];
                    sum += rec[i][k] + rec[k][j];
                    rec[i][j] = Math.max(rec[i][j], sum);
                }
            }
        }
        return rec[0][n + 1];
    }
}
