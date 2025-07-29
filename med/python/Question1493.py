from typing import List


class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        ans = left = 0
        flag = 0
        for right, num in enumerate(nums):
            if num == 0:
                flag += 1
            while flag == 2:
                if nums[left] == 0:
                    flag -= 1
                left += 1
            ans = max(ans, right - left)
        return ans


print(Solution().longestSubarray([1, 1, 1]))
