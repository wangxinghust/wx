package org.wx.problems;

import java.util.TreeMap;

/**
 * 729. 我的日程安排表 I
 */
public class Solution0729 {
    // 区间合并问题，可以利用treeMap解，参考715
    class MyCalendar {
        TreeMap<Integer, Integer> intervals;

        public MyCalendar() {
            intervals = new TreeMap<>();
        }

        public boolean book(int start, int end) {
            if (intervals.isEmpty()) {
                intervals.put(start, end);
                return true;
            }
            if (intervals.containsKey(start)) {
                return false;
            }
            Integer prev = intervals.lowerKey(start);
            Integer next = intervals.higherKey(start);
            if ((prev != null && intervals.get(prev) > start) || (next != null && next < end)) {
                return false;
            }
            intervals.put(start, end);
            return true;
        }
    }

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
}
