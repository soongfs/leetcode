from collections import defaultdict
from typing import List


class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        ans = -1
        record = defaultdict(int)
        for num in nums:
            temp = num
            digit_sum = 0
            while num > 0:
                digit_sum += num % 10
                num //= 10
            if digit_sum in record:
                ans = max(ans, record[digit_sum] + temp)
            record[digit_sum] = max(record[digit_sum], temp)
        return ans


print(Solution().maximumSum([18, 43, 36, 13, 7]))
