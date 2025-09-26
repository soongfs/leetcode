class Solution:
    def makeFancyString(self, s: str) -> str:
        if s == "":
            return ""
        n = len(s)
        ans: str = ""
        ans += s[0]
        state = 0
        for i in range(1, n):
            match state:
                case 0:
                    if s[i - 1] == s[i]:
                        state = 1
                    ans += s[i]
                case 1:
                    if s[i - 1] != s[i]:
                        state = 0
                        ans += s[i]
        return ans


print(Solution().makeFancyString("leeetcode"))
