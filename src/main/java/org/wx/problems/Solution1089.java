package org.wx.problems;

public class Solution1089 {
    public void duplicateZeros(int[] arr) {
        //双指针
        int left = 0, right = 0;
        for (; right < arr.length; left++) {
            if (arr[left] == 0) {
                right += 2;
            } else {
                right++;
            }
        }
        left--;
        // 处理末尾为0，但是只能添加一个0的特殊情况
        if (right > arr.length) {
            right = arr.length - 1;
            arr[right--] = arr[left--];
        } else {
            right = arr.length - 1;
        }
        while (left >= 0) {
            //System.out.print(arr[left]);
            if (arr[left] == 0) {
                arr[right--] = 0;
                arr[right--] = 0;
            } else {
                arr[right--] = arr[left];
            }
            left--;
        }
    }
}
