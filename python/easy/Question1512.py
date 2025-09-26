import collections
from typing import List


class Solution:
    """
    方法三：枚举右维护左+哈希表
        时间复杂度O(n)
        空间复杂度O(n)
    """

    def numIdenticalPairs(self, nums: List[int]) -> int:
        ans = 0
        cnt = collections.defaultdict(int)
        for j, x in enumerate(nums):
            if x in cnt:
                ans += cnt[x]
            cnt[x] += 1
        return ans

    """
    方法二：组合数学优化，使用压行技巧
        时间复杂度O(n)
        空间复杂度O(n)
    """

    # def numIdenticalPairs(self, nums: List[int]) -> int:
    #     m = collections.Counter(nums)
    #     return sum(v * (v - 1) // 2 for _, v in m.items())

    """
    方法一：一般做法，直接遍历枚举
        时间复杂度O(n^2)
        空间复杂度O(1)
    """

    # def numIdenticalPairs(self, nums: List[int]) -> int:
    #     ans = 0
    #     n = len(nums)
    #     for i in range(n):
    #         for j in range(i + 1, n):
    #             if nums[i] == nums[j]:
    #                 ans += 1
    #     return ans


nums = [1, 2, 3, 1, 1, 3]
print(Solution().numIdenticalPairs(nums))
