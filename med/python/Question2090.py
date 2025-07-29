from typing import List


class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        avgs = [-1] * n
        avg = 0
        for i in range(n):
            # right = i
            # right - left + 1 = 2 * k + 1
            # left = i - 2 * k
            avg += nums[i]
            if i - 2 * k < 0:
                continue
            else:
                avgs[i - k] = avg // (2 * k + 1)
                avg -= nums[i - 2 * k]
        return avgs


print(Solution().getAverages([7, 4, 3, 9, 1, 8, 5, 2, 6], 3))
