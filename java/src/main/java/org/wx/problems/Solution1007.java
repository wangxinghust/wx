package org.wx.problems;

public class Solution1007 {
    public int minDominoRotations(int[] tops, int[] bottoms) {
        int x = tops[0], y = bottoms[0];
        int res = Integer.MAX_VALUE;
        boolean can = false;
        // 上层 下层上翻
        boolean curCan = true;
        int num = 0;
        for (int i = 1; i < tops.length; i++) {
            if (tops[i] == x) {
                continue;
            } else if (bottoms[i] == x) {
                num++;
            } else {
                curCan = false;
                break;
            }
        }
        if (curCan) {
            res = num;
        }
        can = can | curCan;
        System.out.println("res1:" + res);

        curCan = true;
        num = 1;
        for (int i = 1; i < tops.length; i++) {
            if (tops[i] == y) {
                continue;
            } else if (bottoms[i] == y) {
                num++;
            } else {
                curCan = false;
                break;
            }
        }
        if (curCan) {
            res = Math.min(res, num);
        }
        can = can | curCan;
        System.out.println("res2:" + res);

        // 下层
        curCan = true;
        num = 0;
        for (int i = 1; i < tops.length; i++) {
            if (bottoms[i] == y) {
                continue;
            } else if (tops[i] == y) {
                num++;
            } else {
                curCan = false;
                break;
            }
        }
        if (curCan) {
            res = Math.min(res, num);
        }
        can = can | curCan;
        System.out.println("res3:" + res);

        curCan = true;
        num = 1;
        for (int i = 1; i < tops.length; i++) {
            if (bottoms[i] == x) {
                continue;
            } else if (tops[i] == x) {
                num++;
            } else {
                curCan = false;
                break;
            }
        }
        if (curCan) {
            res = Math.min(res, num);
        }
        can = can | curCan;
        System.out.println("res4:" + res);

        if (!can) {
            return -1;
        }
        return res;
    }

    public int minDominoRotations2(int[] tops, int[] bottoms) {
        int n = tops.length;

        // faceA for counting the occurence in tops
        // faceB for counting occurence of numbers in bottoms
        // same for counting when both tops and bottoms have same occurences
        int[] faceA = new int[7], faceB = new int[7], same = new int[7];

        for (int i = 0; i < n; ++i) {
            ++faceA[tops[i]];
            ++faceB[bottoms[i]];

            if (tops[i] == bottoms[i])
                ++same[tops[i]];
        }

        int minRotation = Integer.MAX_VALUE;

        // all possibilities from 1 to 6
        for (int i = 1; i <= 6; ++i) {
            if (faceA[i] + faceB[i] - same[i] == n) {
                minRotation = Math.min(minRotation, Math.min(faceA[i], faceB[i]) - same[i]);
            }
        }

        return minRotation == Integer.MAX_VALUE ? -1 : minRotation;
    }
}
