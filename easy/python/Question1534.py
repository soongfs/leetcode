from typing import List


class Solution:
    """
    方法二：枚举优化，前缀和
    """

    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        ans = 0
        n = len(arr)
        total = [0] * 1001
        for j in range(n):
            for k in range(j + 1, n):
                if abs(arr[j] - arr[k]) <= b:
                    lj, rj = arr[j] - a, arr[j] + a
                    lk, rk = arr[k] - c, arr[k] + c
                    l = max(0, lj, lk)
                    r = min(1000, rj, rk)
                    if l <= r:
                        ans += total[r] if l == 0 else total[r] - total[l - 1]
            for i in range(arr[j], 1001):
                total[i] += 1
        return ans

    """
    方法一：直接枚举
    """

    # def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
    #     ans = 0
    #     n = len(arr)
    #     for i in range(n):
    #         for j in range(i + 1, n):
    #             for k in range(j + 1, n):
    #                 if (
    #                     abs(arr[i] - arr[j]) <= a
    #                     and abs(arr[j] - arr[k]) <= b
    #                     and abs(arr[k] - arr[i]) <= c
    #                 ):
    #                     ans += 1
    #     return ans
