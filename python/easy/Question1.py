from typing import List


class Solution:
    """
    方法二：枚举右维护左+哈希表
        时间复杂度O(n)
        空间复杂度O(n)
    """

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        idx = {}
        for j, x in enumerate(nums):
            if target - x in idx:
                return [idx[target - x], j]
            idx[x] = j
        return []

    """
    方法一：暴力枚举
        时间复杂度O(n^2)
        空间复杂度O(1)
    """

    # def twoSum(self, nums: List[int], target: int) -> List[int]:
    #     for i, x in enumerate(nums):
    #         for j, y in enumerate(nums[i + 1 :], start=i + 1):
    #             if x + y == target:
    #                 return [i, j]
    #     return []


sol = Solution()
result = sol.twoSum([2, 7, 11, 15], 9)
print(result)
