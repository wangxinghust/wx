from typing import List


class Solution:
    def minNumberOfHours(self, initialEnergy: int, initialExperience: int, energy: List[int], experience: List[int]) -> int:
        min_number = 0
        for i in range(len(energy)):
            if initialEnergy <= energy[i]:
                min_number += energy[i] - initialEnergy + 1
                initialEnergy = energy[i] + 1
            if initialExperience <= experience[i]:
                min_number += experience[i] - initialExperience + 1
                initialExperience = experience[i] + 1
            initialEnergy -= energy[i]
            initialExperience += experience[i]
        return min_number
