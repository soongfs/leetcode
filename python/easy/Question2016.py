from typing import List


class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        pre_min = nums[0]
        ans = -1
        for x in nums[1:]:
            if x - pre_min > ans and x - pre_min != 0:
                ans = x - pre_min
            if x < pre_min:
                pre_min = x
        return ans


print(Solution().maximumDifference([9, 4, 3, 2]))
