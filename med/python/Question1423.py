from typing import List


class Solution:
    """
    方法一：滑动窗口
        时间复杂度O(n)
        空间复杂度O(1)

        只看首尾贪心是不行的，假设有数组：
        [1, 999, 4, 3, 2]，取三张是 2+3+4，显然不是最优解
    """

    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        # 以剩余的牌数为窗口大小，若不剩牌，不能套用一般逻辑
        # 否则会导致：起始上界为0，计算出下界为1
        if n - k == 0:
            return sum(i for i in cardPoints)
        ans = float("inf")
        temp_sum = 0
        # 窗口长度 = n-k
        for i in range(n):
            temp_sum += cardPoints[i]
            if i - n + k + 1 < 0:
                continue
            else:
                ans = min(ans, temp_sum)
                temp_sum -= cardPoints[i - n + k + 1]
        return sum(i for i in cardPoints) - int(ans)


print(Solution().maxScore([9, 7, 7, 9, 7, 7, 9], 7))
