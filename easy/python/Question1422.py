class Solution:
    def maxScore(self, s: str) -> int:
        cnt = 0
        ans = 0
        for ch in s:
            if ch == "1":
                cnt += 1
        for ch in s[:-1]:
            if ch == "0":
                cnt += 1
            elif ch == "1":
                cnt -= 1
            ans = max(ans, cnt)
        return ans


print(Solution().maxScore("00"))
