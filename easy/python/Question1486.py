class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        ans = 0
        for i in range(n):
            ans ^= start + 2 * i
        return ans


if __name__ == "__main__":
    print(Solution().xorOperation(5, 0))
