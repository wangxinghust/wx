from typing import List


class Solution:
    def occurrencesOfElement(self, nums: List[int], queries: List[int], x: int) -> List[int]:
        index = []
        for i in range(len(nums)):
            if nums[i] == x:
                index.append(i)
        result = [-1]*len(queries)
        for i in range(len(queries)):
            result[i] = -1 if len(index) <= queries[i]-1 else index[queries[i]-1]
        return result

class SolutionV2:
    def occurrencesOfElement(self, nums: List[int], queries: List[int], x: int) -> List[int]:
        indices = [i for i, num in enumerate(nums) if num == x]
        return [-1 if len(indices) < q else indices[q - 1] for q in queries]