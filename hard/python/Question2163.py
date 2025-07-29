import heapq
from typing import List


class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        m = len(nums)
        n = m // 3
        min_h = nums[-n:]  # 最小堆
        heapq.heapify(min_h)

        suf_max = [0] * (m - n + 1)  # 后缀最大和
        suf_max[-1] = sum(min_h)
        for i in range(m - n - 1, n - 1, -1):
            suf_max[i] = suf_max[i + 1] + nums[i] - heapq.heappushpop(min_h, nums[i])

        max_h = [-x for x in nums[:n]]  # 最大堆
        heapq.heapify(max_h)

        pre_min = -sum(max_h)
        ans = pre_min - suf_max[n]
        for i in range(n, m - n):
            pre_min += nums[i] + heapq.heappushpop(max_h, -nums[i])
            ans = min(ans, pre_min - suf_max[i + 1])
        return ans


print(Solution().minimumDifference([3, 1, 2]))
