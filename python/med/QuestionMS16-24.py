from collections import defaultdict
from typing import List


class Solution:
    def pairSums(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        cnt = defaultdict(int)
        for num in nums:
            if target - num in cnt:
                cnt[target - num] -= 1
                if cnt[target - num] == 0:
                    del cnt[target - num]
                ans.append([target - num, num])
            else:
                cnt[num] += 1
        return ans


print(Solution().pairSums([5, 6, 5, 6], 11))
