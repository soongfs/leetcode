import collections
from typing import List


class Solution:
    """
    方法二：Counter生成字典+组合数学
        时间复杂度O(n)
        空间复杂度O(n)
    """

    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        m = collections.Counter(w / h for w, h in rectangles)
        return sum(v * (v - 1) // 2 for _, v in m.items())

    """
    方法一：枚举右维护左
        时间复杂度O(n)
        空间复杂度O(n)
    """

    # def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
    #     ans = 0
    #     cnt = collections.defaultdict(int)
    #     for j, matrix in enumerate(rectangles):
    #         if matrix[0] / matrix[1] in cnt:
    #             ans += cnt[matrix[0] / matrix[1]]
    #         cnt[matrix[0] / matrix[1]] += 1
    #     return ans


print(Solution().interchangeableRectangles([[4, 8], [3, 6], [10, 20], [15, 30]]))
