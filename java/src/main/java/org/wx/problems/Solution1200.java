package org.wx.problems;

import java.util.*;

public class Solution1200 {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int sub = arr[arr.length - 1] - arr[0];
        Map<Integer, List<List<Integer>>> absDiff = new HashMap<>();
        for (int i = 0; i < arr.length - 1; i++) {
            int abs = arr[i + 1] - arr[i];
            if (abs <= sub) {
                sub = abs;
                //System.out.println("i="+i+", sub= "+sub);
                List<Integer> row = new ArrayList<>();
                row.add(arr[i]);
                row.add(arr[i + 1]);
                List<List<Integer>> diff = absDiff.getOrDefault(abs, new ArrayList<>());
                diff.add(row);
                absDiff.put(abs, diff);
            }
        }
        //System.out.println(sub);
        return absDiff.get(sub);
    }
}
