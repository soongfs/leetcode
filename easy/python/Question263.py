class Solution:
    """
    方法一：循环消去所有2、3、5因子
        时间复杂度O(logn)
        空间复杂度O(1)
    """

    def isUgly(self, n: int) -> bool:
        if n <= 0:
            return False
        while n > 1:
            if n % 2 == 0:
                n //= 2
            elif n % 3 == 0:
                n //= 3
            elif n % 5 == 0:
                n //= 5
            else:
                return False
        return True


print(Solution().isUgly(14))
