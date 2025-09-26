from collections import defaultdict
from typing import List


class Solution:
    def maxSum(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        ans: int = 0
        hash_map = defaultdict(int)
        # at least one
        flag: bool = False
        for num in nums:
            if num <= 0:
                continue
            else:
                if num in hash_map:
                    continue
                else:
                    flag = True
                    ans += num
                    hash_map[num] += 1
        if flag == False:
            return max(nums)
        return ans


print(Solution().maxSum([1, 1, 0, 1, 1]))
