from typing import List


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        # 这里的ans和aver其实是总和，起变量名要见名知意，检讨
        ans, aver = float("-inf"), 0
        for i in range(len(nums)):
            # right = i
            # right - left + 1 = k
            # left = i - k + 1
            aver += nums[i]
            if i < k - 1:
                continue
            else:
                ans = max(ans, aver)
                aver -= nums[i - k + 1]
        return ans / k


print(Solution().findMaxAverage([-1], 1))
