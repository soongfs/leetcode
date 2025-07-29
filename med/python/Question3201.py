from typing import List


class Solution:
    """
    方法一：分四种情形计数
        时间复杂度O(n)
        空间复杂度O(1)
    """

    def maximumLength(self, nums: List[int]) -> int:
        n = len(nums)
        # 共四种可能的情形
        # [e, e, e, ...]
        # [o, o, o, ...]
        # [e, o, e, ...]
        # [o, e, o, ...]
        max_sub = 0
        case_ee = 0
        case_oo = 0
        case_eo = 0
        case_oe = 0
        state_eo = 0
        state_oe = 0
        for num in nums:
            if num % 2 == 0:
                case_ee += 1
                if state_eo == 0:
                    state_eo = 1
                    case_eo += 1
                if state_oe == 1:
                    state_oe = 0
                    case_oe += 1
            else:
                case_oo += 1
                if state_oe == 0:
                    state_oe = 1
                    case_oe += 1
                if state_eo == 1:
                    state_eo = 0
                    case_eo += 1
        return max(case_ee, case_oo, case_eo, case_oe)


print(Solution().maximumLength([1, 2, 1, 1, 2, 1, 2]))
