package org.wx.problems;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * @author Wang Xing
 * @date 8/5/21
 */
public class Solution0228 {
    /**
     * 228. Summary Ranges
     * 2021-8-4 01:06:30
     */
    public List<String> summaryRanges(int[] nums) {
        if (nums.length == 0) {
            return new ArrayList<>();
        }
        List<String> result = new LinkedList<>();
        int left = nums[0], right = nums[0];
        for (int i = 0; i < nums.length; i++) {
            if (i + 1 >= nums.length) {
                if (left == right) {
                    result.add(String.valueOf(left));
                } else {
                    result.add(left + "->" + right);
                }
                break;
            }


            if (nums[i + 1] == right + 1) {
                right = nums[i + 1];
            } else {
                if (left == right) {
                    result.add(String.valueOf(left));
                } else {
                    result.add(left + "->" + right);
                }
                left = right = nums[i + 1];
            }
        }
        return result;
    }
}
