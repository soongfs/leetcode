class Solution:
    """
    方法二：数学，求数根，推导看题解
    """

    def addDigits(self, num: int) -> int:
        return (num - 1) % 9 + 1 if num else 0

    """
    方法一：模拟
    """

    # def addDigits(self, num: int) -> int:
    #     while num >= 10:
    #         temp = 0
    #         while num > 0:
    #             temp += num % 10
    #             num //= 10
    #         num = temp
    #     return num


print(Solution().addDigits(38))
