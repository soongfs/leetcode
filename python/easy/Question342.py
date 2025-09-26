class Solution:
    """
    方法二（错误）：
        在给出的数据范围 [-2^31, 2^31-1] 中
        4^x 必然是 4^16 = 4294967296 的因子

        在 Question326 中，判断 3 的幂，确实可以。
        然而 2^x 也是 4^16 的因子，这个方法是错的
    """

    # def isPowerOfFour(self, n: int) -> bool:
    #     if n <= 0:
    #         return False
    #     if 4294967296 % n == 0:
    #         return True
    #     else:
    #         return False

    """
    方法一：循环判断
    """

    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0:
            return False
        while n % 4 == 0:
            n //= 4
        return n == 1


if __name__ == "__main__":
    print(Solution().isPowerOfFour(16))
