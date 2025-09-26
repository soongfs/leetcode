from typing import List


class Solution:
    """
    方法一：滑动窗口+循环加法
        时间复杂度O(n)
        空间复杂度O(n)
    """

    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        if k == 0:
            return [0] * n
        ans = [0] * n
        temp_sum = 0
        size = 0
        for i in range(n + abs(k) - 1):
            temp_sum += code[self.circular(0, i, n)]
            size += 1
            if size == abs(k):
                if k > 0:
                    ans[self.circular(0, i - 1 * k, n)] = temp_sum
                elif k < 0:
                    ans[self.circular(0, i + 1, n)] = temp_sum
                temp_sum -= code[self.circular(0, i - 1 * abs(k) + 1, n)]
                size -= 1
        return ans

    def circular(self, x: int, y: int, n: int) -> int:
        """
        循环加法
            传入：被加数x，加数y，长度n
            返回：x循环+y
        """
        return (x + y + n) % n


print(Solution().decrypt([2, 4, 9, 3], -2))
