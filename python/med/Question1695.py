from collections import defaultdict
from typing import List


class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        ans, left, temp_sum = 0, 0, 0
        cnt = defaultdict(int)
        for i, x in enumerate(nums):
            cnt[x] += 1
            temp_sum += x
            while cnt[x] > 1:
                cnt[nums[left]] -= 1
                temp_sum -= nums[left]
                left += 1
            ans = max(ans, temp_sum)
        return ans


print(Solution().maximumUniqueSubarray([4, 2, 4, 5, 6]))
