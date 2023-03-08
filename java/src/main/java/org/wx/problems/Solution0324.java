package org.wx.problems;

import java.util.Arrays;
import java.util.Random;

public class Solution0324 {
    /**
     * 方法一：排序
     *
     * @param nums
     */
    public void wiggleSort(int[] nums) {
        int[] arr = nums.clone();
        Arrays.sort(arr);
        int n = nums.length;
        int x = (n + 1) / 2;
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--) {
            nums[i] = arr[j];
            if (i + 1 < n) {
                nums[i + 1] = arr[k];
            }
        }
    }

    /**
     * 方法二：三向切分
     */
    Random random = new Random();

    public void wiggleSort2(int[] nums) {
        int n = nums.length;
        int x = (n + 1) / 2;
        // 中间下标
        int mid = x - 1;
        // 找中位数
        int target = findKthLargest(nums, n - mid);
        // 三向快排，参考75题，双指针法
        for (int k = 0, i = 0, j = n - 1; k <= j; k++) {
            if (nums[k] > target) {
                // 优化，也可以直接while swap
                while (j > k && nums[j] > target) {
                    j--;
                }
                swap(nums, k, j--);
            }
            // 优化前
//            while (j > k && nums[k] > target) {
//                swap(nums, k, j--);
//            }
            if (nums[k] < target) {
                swap(nums, k, i++);
            }
        }
        int[] arr = nums.clone();
        // 构造同方法一
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--) {
            nums[i] = arr[j];
            if (i + 1 < n) {
                nums[i + 1] = arr[k];
            }
        }
    }

    // 快排找第k大
    public int findKthLargest(int[] nums, int k) {
        return quickSelect(nums, 0, nums.length - 1, nums.length - k);
    }

    public int quickSelect(int[] a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    public int randomPartition(int[] a, int l, int r) {
        int i = random.nextInt(r - l + 1) + l;
        swap(a, i, r);
        return partition(a, l, r);
    }

    public int partition(int[] a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a, ++i, j);
            }
        }
        swap(a, i + 1, r);
        return i + 1;
    }

    public void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    // 方法三：索引转换
    public void wiggleSort3(int[] nums) {
        int n = nums.length;
        int x = (n + 1) / 2;
        int mid = x - 1;
        int target = findKthLargest(nums, n - mid);
        for (int k = 0, i = 0, j = n - 1; k <= j; k++) {
            if (nums[transAddress(k, n)] > target) {
                while (j > k && nums[transAddress(j, n)] > target) {
                    j--;
                }
                swap(nums, transAddress(k, n), transAddress(j--, n));
            }
            if (nums[transAddress(k, n)] < target) {
                swap(nums, transAddress(k, n), transAddress(i++, n));
            }
        }
    }

    public int transAddress(int i, int n) {
        // 关键在公式推导，需要找规律，n|1也非常巧妙
        return (2 * n - 2 * i - 1) % (n | 1);
    }

    // 方法四：递归优化
    // 递归优化即使用非递归的方式实现快排，也就是双指针+while循环，避免了自己调用自己
    public int findKthLargest2(int[] nums, int k) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int pivot = random.nextInt(right - left + 1) + left;
            int newPivot = partitionAroundPivot(left, right, pivot, nums);
            if (newPivot == k - 1) {
                return nums[newPivot];
            } else if (newPivot > k - 1) {
                right = newPivot - 1;
            } else {
                left = newPivot + 1;
            }
        }
        return nums[k - 1];
    }

    public int partitionAroundPivot(int left, int right, int pivot, int[] nums) {
        int pivotValue = nums[pivot];
        int newPivot = left;
        swap(nums, pivot, right);
        for (int i = left; i < right; ++i) {
            if (nums[i] > pivotValue) {
                swap(nums, i, newPivot++);
            }
        }
        swap(nums, right, newPivot);
        return newPivot;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{1, 5, 1, 1, 6, 4};
        Solution0324 solution0324 = new Solution0324();
        solution0324.wiggleSort(nums);
    }
}
