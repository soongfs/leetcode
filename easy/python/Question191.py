class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        while n > 0:
            cnt += n & 1
            n >>= 1
        return cnt


if __name__ == "__main__":
    print(Solution().hammingWeight(11))
