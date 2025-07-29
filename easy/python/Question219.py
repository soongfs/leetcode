# from collections import defaultdict
from typing import List


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        # idx = defaultdict(int)
        # for j, x in enumerate(nums):
        #     if x in idx:
        #         return True
        #     idx[x] += 1
        #     if j >= k:
        #         idx[nums[j - k]] -= 1
        #         if idx[nums[j - k]] == 0:
        #             del idx[nums[j - k]]
        # return False
        last = {}
        for i, x in enumerate(nums):
            if x in last and i - last[x] <= k:
                return True
            last[x] = i
        return False


print(Solution().containsNearbyDuplicate([1, 2, 3, 1], 3))
