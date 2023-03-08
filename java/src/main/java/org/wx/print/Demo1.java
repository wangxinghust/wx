package org.wx.print;

import java.util.Arrays;
import java.util.Scanner;

public class Demo1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入");
        while (scanner.hasNext()) {
            String str = scanner.next();
            String[] split = str.split(",");
            System.out.println(Arrays.toString(split));
            int[] nums = new int[split.length];
            for (int i = 0; i < nums.length; i++) {
                nums[i] = Integer.parseInt(split[i]);
            }
            System.out.println(Arrays.toString(nums));
        }
    }
}
