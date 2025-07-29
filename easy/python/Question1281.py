class Solution:
    """
    方法一：模拟
        时间复杂度O(logn)
        空间复杂度O(1)
    """

    def subtractProductAndSum(self, n: int) -> int:
        prod = 1
        sum = 0
        while n > 0:
            prod *= n % 10
            sum += n % 10
            n //= 10
        return prod - sum


print(Solution().subtractProductAndSum(4421))
