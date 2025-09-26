from collections import defaultdict
from typing import List


class Solution:
    """
    方法一：枚举右维护左+哈希表
    """

    def maxOperations(self, nums: List[int], k: int) -> int:
        ans = 0
        cnt = defaultdict(int)
        for num in nums:
            if k - num in cnt:
                cnt[k - num] -= 1
                if cnt[k - num] == 0:
                    del cnt[k - num]
                ans += 1
            else:
                cnt[num] += 1
        return ans


print(Solution().maxOperations([3, 1, 3, 4, 3], 6))
