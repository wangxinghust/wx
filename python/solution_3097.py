from typing import List


class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        """similar with 3095

        Args:
            nums (List[int]): _description_
            k (int): _description_

        Returns:
            int: _description_
        """
        res = -1

        or_res = 0
        index = 0
        while index < len(nums):
            or_res |= nums[index]
            if or_res >= k:
                left_index = index
                right_or_res = 0
                while left_index >= 0:
                    right_or_res |= nums[left_index]
                    if right_or_res >= k:
                        res = (
                            min(res, index - left_index + 1)
                            if res != -1
                            else index - left_index + 1
                        )
                        #  init again
                        or_res = 0
                        index = left_index
                        break
                    left_index -= 1
            index += 1
        return res
