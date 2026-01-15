from typing import List


class Solution:
    def f(self, a: List[int]) -> int:
        a.sort()
        mx = cnt = 0
        for i, x in enumerate(a):
            if i > 0 and x == a[i - 1] + 1:
                cnt += 1
            else:
                cnt = 1
            mx = max(mx, cnt)
        return mx

    def maximizeSquareHoleArea(
        self, n: int, m: int, hBars: List[int], vBars: List[int]
    ) -> int:
        side = min(self.f(hBars), self.f(vBars)) + 1
        return side * side
