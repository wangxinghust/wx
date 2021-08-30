package org.wx.problems;

/**
 * 330. Patching Array
 */
public class Solution0330 {
    public static void main(String[] args) {
        Solution0330 solution = new Solution0330();
        int res = solution.minPatches(new int[]{1, 2, 31, 33}, 2147483647);
        System.out.println(res);
    }

    /**
     * 优化方案是从后往前遍历sum数组，避免使用temp数组
     * 存在n=2^31 - 1的情况，因此不能用len=n+1的方案
     * 而且申请这么大的数组也不靠谱
     */
    public int minPatches(int[] nums, int n) {
        int len = n + 1;
        boolean[] sum = new boolean[len];
        sum[0] = true;
        boolean[] temp = new boolean[len];
        for (int i = 0; i < nums.length; i++) {
            System.arraycopy(sum, 0, temp, 0, len);
            for (int j = 0; j < len - nums[i]; j++) {
                if (sum[j]) {
                    temp[j + nums[i]] = true;
                }
            }
            System.arraycopy(temp, 0, sum, 0, len);
        }
        int cnt = 0;
        for (int i = 1; i < len; i++) {
            if (!sum[i]) {
                ++cnt;
                System.arraycopy(sum, 0, temp, 0, len);
                for (int j = 0; j < len - i; j++) {
                    if (sum[j]) {
                        temp[j + i] = true;
                    }
                }
                System.arraycopy(temp, 0, sum, 0, len);
            }
        }
        return cnt;
    }
}
