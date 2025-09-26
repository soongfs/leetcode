class Solution:
    def reverse(self, x: int) -> int:
        sign = 1
        if x < 0:
            sign = -1
            x *= -1
        reverse = 0
        while x > 0:
            reverse *= 10
            reverse += x % 10
            x //= 10
        ans = sign * reverse
        if not (ans >= -(2**31) and ans <= 2**31 - 1):
            return 0
        return ans


if __name__ == "__main__":
    print(Solution().reverse(-123))
