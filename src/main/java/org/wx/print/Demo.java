package org.wx.print;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Demo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Integer> nums = new ArrayList<>();
        System.out.println("请输入");
        while (scanner.hasNextInt()) {
            nums.add(scanner.nextInt());
        }
        System.out.println(nums);
    }
}
