from typing import List


class Solution:
    """
    方法一：模拟
        时间复杂度O(n)
        空间复杂度O(n)
    """

    def shuffle(self, nums: List[int], n: int) -> List[int]:
        ans = []
        for i in range(n):
            ans.append(nums[i])
            ans.append(nums[i + n])
        return ans


nums = [
    2,
    5,
    1,
    3,
    4,
    7,
]
n = 3
print(Solution().shuffle(nums, n))
