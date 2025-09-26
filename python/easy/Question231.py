class Solution:
    """
    方法二：利用n&(n-1)去除最低的1
        也可以利用n&(-n)，仅保留最低的1
    """

    def isPowerOfTwo(self, n: int) -> bool:
        # if n <= 0:
        #     return False
        # if n & (n - 1) == 0:
        #     return True
        # else:
        #     return False

        # 可以压行写成这样
        # return n > 0 and n & (n - 1) == 0
        # 或者
        return n > 0 and n & (-n) == n

    """
    方法一：计数1位的个数，有且仅有一个则是2的幂
    """

    # def isPowerOfTwo(self, n: int) -> bool:
    #     cnt = 0
    #     while n > 0:
    #         cnt += n & 1
    #         n >>= 1
    #     return cnt == 1


if __name__ == "__main__":
    print(Solution().isPowerOfTwo(128))
