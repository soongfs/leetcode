from typing import List


class Solution:
    """
    方法一：滑动窗口
        计算能挽回的顾客的最大值
    """

    def maxSatisfied(
        self, customers: List[int], grumpy: List[int], minutes: int
    ) -> int:
        n = len(customers)
        ans = 0
        save = 0
        other = 0
        for i in range(n):
            if grumpy[i] == 1:
                save += customers[i]
            else:
                other += customers[i]
            if i - minutes + 1 < 0:
                continue
            else:
                ans = max(ans, save)
                if grumpy[i - minutes + 1] == 1:
                    save -= customers[i - minutes + 1]
        return other + ans


print(Solution().maxSatisfied([1, 0, 1, 2, 1, 1, 7, 5], [0, 1, 0, 1, 0, 1, 0, 1], 3))
# [1, 0, 1, 2, 1, 1, 7, 5]
# [0, 1, 0, 1, 0, 1, 0, 1]
