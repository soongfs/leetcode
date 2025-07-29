import collections
from typing import List


class Solution:
    """
    方法一：枚举右维护左
        时间复杂度O(n)
        空间复杂度O(n)
    """

    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        ans = 0
        cnt = collections.defaultdict(int)
        for j, x in enumerate(dominoes):
            # 列表list是不可哈希的，所以用元组tuple
            if (x[0], x[1]) in cnt:
                ans += cnt[(x[0], x[1])]
            if x[0] != x[1] and (x[1], x[0]) in cnt:
                ans += cnt[(x[1], x[0])]
            cnt[(x[0], x[1])] += 1
        return ans


print(Solution().numEquivDominoPairs([[1, 2], [1, 2], [1, 1], [1, 2], [2, 2]]))
