from typing import List


class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        nums_sum = sum(nums)
        prefix_sum = 0
        cnt = 0
        for i in range(len(nums)-1):
            prefix_sum += nums[i]
            if prefix_sum >= nums_sum - prefix_sum:
                cnt += 1
        return cnt