from collections import defaultdict
from typing import List


class Solution:
    def getLargestOutlier(self, nums: List[int]) -> int:
        ans = -1000
        total_sum = 0
        hash_map = defaultdict(int)
        for num in nums:
            total_sum += num
            hash_map[num] += 1
        for num in nums:
            hash_map[num] -= 1
            if (total_sum - num) % 2 == 0:
                if (total_sum - num) // 2 in hash_map and hash_map[
                    (total_sum - num) // 2
                ] > 0:
                    ans = max(ans, num)
            hash_map[num] += 1
        return ans


print(Solution().getLargestOutlier([-2, -1, -3, -6, 4]))
