from typing import List


class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        last = {}
        ans = len(cards)
        flag = False
        for i, x in enumerate(cards):
            if x in last:
                ans = min(ans, i - last[x] + 1)
                flag = True
            last[x] = i
        return ans if flag else -1


print(Solution().minimumCardPickup([3, 4, 2, 3, 4, 7]))
