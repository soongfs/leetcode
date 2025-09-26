from collections import defaultdict
from typing import List


class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ans = 0
        temp_sum = 0
        window = defaultdict(int)
        for i in range(n):
            temp_sum += nums[i]
            window[nums[i]] += 1
            if i - k + 1 < 0:
                continue
            else:
                if len(window) == k:
                    ans = max(ans, temp_sum)
                temp_sum -= nums[i - k + 1]
                window[nums[i - k + 1]] -= 1
                if window[nums[i - k + 1]] == 0:
                    del window[nums[i - k + 1]]
        return ans


print(Solution().maximumSubarraySum([1, 5, 4, 2, 9, 9, 9], 3))
