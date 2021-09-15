package org.wx.problems;

/**
 * 978. Longest Turbulent Subarray
 */
public class Solution0978 {
    public static void main(String[] args) {
        Solution0978 solution = new Solution0978();
        int ans = solution.maxTurbulenceSize(new int[]{9, 9});
        System.out.println(ans);
    }

    public int maxTurbulenceSize(int[] arr) {
        int left = 1, right = 1, ans = 1;
        while (left < arr.length && right < arr.length) {
            right = left + 1;
            if (arr[left] == arr[left - 1]) {
                left = right;
                continue;
            }
            boolean isGreater = arr[left] > arr[left - 1];
            isGreater = !isGreater;
            while (right < arr.length) {
                if (isGreater && arr[right] > arr[right - 1]) {
                    isGreater = !isGreater;
                    right++;
                } else if (!isGreater && arr[right] < arr[right - 1]) {
                    isGreater = !isGreater;
                    right++;
                } else {
                    break;
                }
            }
            ans = Math.max(ans, right - left + 1);
            left = right;
        }
        return ans;
    }

    /**
     * 官方答案，利用compare直接取出比较后的-1，0，1三个状态
     * compare 其实也就是一个三元表达式
     */
    public int maxTurbulenceSize2(int[] arr) {
        int N = arr.length;
        int ans = 1;
        int anchor = 0;

        for (int i = 1; i < N; ++i) {
            int c = Integer.compare(arr[i - 1], arr[i]);
            if (c == 0) {
                anchor = i;
            } else if (i == N - 1 || c * Integer.compare(arr[i], arr[i + 1]) != -1) {
                ans = Math.max(ans, i - anchor + 1);
                anchor = i;
            }
        }

        return ans;
    }
}
