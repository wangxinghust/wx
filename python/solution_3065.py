from typing import List


class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        cnt = 0
        for n in nums:
            if n < k:
                cnt +=1
        return cnt