from typing import List


class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        f = [[0] * k for _ in range(k)]
        for x in nums:
            x %= k
            for y, fxy in enumerate(f[x]):
                f[y][x] = fxy + 1
        return max(map(max, f))


print(Solution().maximumLength([1, 2, 3, 4, 5], 2))
