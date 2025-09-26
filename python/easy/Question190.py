class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        for _ in range(32):
            ans <<= 1
            if n & 1 == 1:
                ans += 1
            n >>= 1
        return ans


if __name__ == "__main__":
    print(Solution().reverseBits(0b11111111111111111111111111111101))
