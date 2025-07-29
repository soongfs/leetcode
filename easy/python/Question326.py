import math


class Solution:
    """
    方法二：
        在给出的数据范围 [-2^31, 2^31-1] 中
        3^x 必然是 3^19 = 1162261467 的因子
    """

    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        if 1162261467 % n == 0:
            return True
        else:
            return False

    """
    方法一：循环判断
    """

    # def isPowerOfThree(self, n: int) -> bool:
    #     if n <= 0:
    #         return False
    #     while n % 3 == 0:
    #         n //= 3
    #     return n == 1


if __name__ == "__main__":
    print(Solution().isPowerOfThree(28))
