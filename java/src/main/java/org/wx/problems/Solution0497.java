package org.wx.problems;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * 思路类似，但无法ac，前缀和+二分查找
 * 错误原因貌似是二分查找不同
 */
public class Solution0497 {
    private int[][] rects;
    private int[] areas;
    private int sum;
    private Random random;

    public Solution0497(int[][] rects) {
        this.areas = new int[rects.length];
        for (int i = 0; i < rects.length; i++) {
            this.areas[i] = (rects[i][2] - rects[i][0]) * (rects[i][3] - rects[i][1]);
        }
        for (int i = 1; i < this.areas.length; i++) {
            this.areas[i] += this.areas[i - 1];
        }
        this.sum = this.areas[areas.length - 1];
        this.random = new Random();
        this.rects = rects;
    }

    public int[] pick() {
        int r = this.random.nextInt(sum);
        int index = BSearchUpperBound(r);
        int[] res = new int[2];
        // 以下可以不用random，而是直接将r转换成具体的点，因为都是int类型，可以从面积向点映射
//        res[0] = this.random.nextInt(this.rects[index][0], this.rects[index][2] + 1);
//        res[1] = this.random.nextInt(this.rects[index][1], this.rects[index][3] + 1);
        return res;
    }

    private int BSearchUpperBound(int r) {
        int low = 0, high = this.areas.length - 1;
        int mid = high / 2;
        while (high > low) {
            if (this.areas[mid] > r)
                high = mid;
            else
                low = mid + 1;

            mid = (low + high) / 2;
        }

        return mid;
    }
}

/**
 * 官方答案
 */
class Solution {
    Random rand;
    List<Integer> arr;
    int[][] rects;

    public Solution(int[][] rects) {
        rand = new Random();
        arr = new ArrayList<Integer>();
        arr.add(0);
        this.rects = rects;
        for (int[] rect : rects) {
            int a = rect[0], b = rect[1], x = rect[2], y = rect[3];
            arr.add(arr.get(arr.size() - 1) + (x - a + 1) * (y - b + 1));
        }
    }

    public int[] pick() {
        int k = rand.nextInt(arr.get(arr.size() - 1));
        int rectIndex = binarySearch(arr, k + 1) - 1;
        k -= arr.get(rectIndex);
        int[] rect = rects[rectIndex];
        int a = rect[0], b = rect[1], y = rect[3];
        int col = y - b + 1;
        int da = k / col;
        int db = k - col * da;
        return new int[]{a + da, b + db};
    }

    private int binarySearch(List<Integer> arr, int target) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            int num = arr.get(mid);
            if (num == target) {
                return mid;
            } else if (num > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}
