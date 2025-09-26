from typing import List


class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        left, right, ans = 0, len(arr) - 1, 0
        while left < right:
            mid = (left + right) // 2
            if arr[mid] < arr[mid + 1]:
                left = mid + 1
            elif arr[mid] > arr[mid + 1]:
                ans = mid
                right = mid
        return ans


print(Solution().peakIndexInMountainArray([40, 48, 61, 75, 100, 99, 98, 39, 30, 10]))
