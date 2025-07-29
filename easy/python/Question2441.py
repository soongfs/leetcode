from typing import List


class Solution:
    """
    方法一：枚举右维护左+哈希表
        时间复杂度O(n)
        空间复杂度O(n)
    """

    def findMaxK(self, nums: List[int]) -> int:
        idx = {}
        ans = -1
        for j, x in enumerate(nums):
            if -1 * x in idx:
                ans = max(ans, abs(x))
            idx[x] = j
        return ans


print(Solution().findMaxK([-10, 8, 6, 7, -2, -3]))
