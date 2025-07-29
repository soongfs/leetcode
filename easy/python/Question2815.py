from typing import List


class Solution:
    def maxSum(self, nums: List[int]) -> int:
        record = {}
        max_sum = -1
        for num in nums:
            temp = num
            largest = 0
            while num > 0:
                largest = max(largest, num % 10)
                num //= 10
            if largest in record:
                max_sum = max(max_sum, record[largest] + temp)
            record[largest] = max(record.get(largest, 0), temp)
        return max_sum


print(Solution().maxSum([1, 2, 3, 4]))
