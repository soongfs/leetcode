from collections import defaultdict
from typing import List


class Solution:
    """
    方法一：滑动窗口+字典
        时间复杂度O(n)
        空间复杂度O(n)
    """

    def maxSum(self, nums: List[int], m: int, k: int) -> int:
        n = len(nums)
        ans = 0
        temp_sum = 0
        # window = {}
        # 使用defaultdict()可以在访问不存在的键时自动创建该键并赋予默认值
        # int表示默认键值为整数，整数的默认值为0
        window = defaultdict(int)
        for i in range(n):
            temp_sum += nums[i]
            # window[nums[i]] = window[nums[i]] + 1 if nums[i] in window else 1
            # 优化后
            window[nums[i]] += 1
            if i - k + 1 < 0:
                continue
            else:
                if len(window) >= m:
                    ans = max(ans, temp_sum)
                temp_sum -= nums[i - k + 1]
                # if window[nums[i - k + 1]] > 1:
                #     window[nums[i - k + 1]] -= 1
                # elif window[nums[i - k + 1]] == 1:
                #     del window[nums[i - k + 1]]
                # 左侧的元素一定进入过字典，无需担心不存在该键
                window[nums[i - k + 1]] -= 1
                if window[nums[i - k + 1]] == 0:
                    del window[nums[i - k + 1]]
        return ans


print(Solution().maxSum([1, 1, 1, 3], 2, 2))
