package org.wx.problems;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Solution0954 {
    public static void main(String[] args) {
        int[] arr = {1, 2, 1, -8, 8, -4, 4, -4, 2, -2};
        Solution0954 solution = new Solution0954();
        System.out.println(solution.canReorderDoubled(arr));
    }

    /**
     * 954. Array of Doubled Pairs
     */
    public boolean canReorderDoubled(int[] arr) {
        int left = 0, right = 0, zero = 0;
        int[] arrLeft = new int[arr.length];
        int[] arrRight = new int[arr.length];
        Map<Integer, Integer> countLeft = new HashMap<>();
        Map<Integer, Integer> countRight = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == 0) {
                zero++;
            } else if (arr[i] < 0) {
                arrLeft[left++] = arr[i];
                countLeft.merge(arr[i], 1, Integer::sum);
            } else if (arr[i] > 0) {
                arrRight[right++] = arr[i];
                countRight.merge(arr[i], 1, Integer::sum);
            }
        }
        if (zero % 2 == 1 || left % 2 == 1 || right % 2 == 1) {
            return false;
        }
        Arrays.sort(arrLeft);
        for (int i = left - 1; i >= 0; i--) {
            if (countLeft.getOrDefault(arrLeft[i], 0) == 0) {
                continue;
            }
            Integer cnt = countLeft.getOrDefault(2 * arrLeft[i], 0);
            if (cnt <= 0) {
                return false;
            } else {
                countLeft.merge(arrLeft[i], -1, Integer::sum);
                countLeft.merge(2 * arrLeft[i], -1, Integer::sum);
            }
        }
        Arrays.sort(arrRight);
        for (int i = arr.length - right; i < arr.length; i++) {
            if (countRight.getOrDefault(arrRight[i], 0) == 0) {
                continue;
            }
            Integer cnt = countRight.getOrDefault(2 * arrRight[i], 0);
            if (cnt <= 0) {
                return false;
            } else {
                countRight.merge(arrRight[i], -1, Integer::sum);
                countRight.merge(2 * arrRight[i], -1, Integer::sum);
            }
        }
        return true;
    }
}
