# 1899. Merge Triplets to Form Target Triplet

from typing import List



class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:

        have_one = False
        have_two = False
        have_three = False


        for t in triplets:
            if t[0] > target[0] or t[1] > target[1] or t[2] > target[2]:
                continue

            if t[0] == target[0]:
                have_one = True
            if t[1] == target[1]:
                have_two = True
            if t[2] == target[2]:
                have_three = True

        return have_one and have_two and have_three
