package org.wx.problems;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class Solution0895 {
    class FreqStack {

        Map<Integer, Integer> freq;
        Map<Integer, Stack<Integer>> group;
        int maxFreq;

        public FreqStack() {
            this.freq = new HashMap<>();
            this.group = new HashMap<>();
            this.maxFreq = 0;
        }

        public void push(int val) {
            int f = this.freq.getOrDefault(val, 0) + 1;
            this.freq.put(val, f);
            if (f > this.maxFreq) {
                this.maxFreq = f;
            }
            this.group.computeIfAbsent(f, z -> new Stack<>()).push(val);
        }

        public int pop() {
            int x = this.group.get(maxFreq).pop();
            if (this.group.get(this.maxFreq).size() == 0) {
                this.maxFreq--;
            }
            this.freq.put(x, this.freq.get(x) - 1);
            return x;
        }
    }
}
