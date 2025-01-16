from heapq import heapify, heappop, heappush
from queue import PriorityQueue
from typing import List


class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        """Add min(x, y) * 2 + max(x, y)
        if x < y, than add 2x + y
        if x == y, than add 3x
        if x > y, than add 2y + x
        remove and add , need number added greater than number removed, so
        assume x <= y, than 2x + y >= x + y, than x >= 0, but number always greater or euqal to 1

        Args:
            nums (List[int]): _description_
            k (int): _description_

        Returns:
            int: _description_
        """
        priority_queue = PriorityQueue()
        for num in nums:
            priority_queue.put(num)
        operations = 0
        while priority_queue.qsize() >= 2:
            x = priority_queue.get()
            y = priority_queue.get()
            if x >= k:
                break
            priority_queue.put(2 * x + y)
            operations += 1
        return operations


class SolutionV2:
    def minOperations(self, nums: List[int], k: int) -> int:
        res = 0
        h = nums[:]
        heapify(h)
        while h[0] < k:
            x = heappop(h)
            y = heappop(h)
            heappush(h, x + x + y)
            res += 1
        return res
