from typing import List


class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        ans, aver, k_threshold = 0, 0, k * threshold
        for i in range(len(arr)):
            aver += arr[i]
            if i < k - 1:
                continue
            else:
                if aver >= k_threshold:
                    ans += 1
                aver -= arr[i - k + 1]
        return ans


print(Solution().numOfSubarrays([2, 2, 2, 2, 5, 5, 5, 8], 3, 4))
