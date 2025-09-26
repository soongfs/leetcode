from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        pre_min = prices[0]
        ans = 0
        for x in prices[1:]:
            if x - pre_min > ans:
                ans = x - pre_min
            if x < pre_min:
                pre_min = x
        return ans


print(Solution().maxProfit([7, 6, 4, 3, 1]))
