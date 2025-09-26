class Solution:
    """
    方法一：滑动窗口
        时间复杂度O(n)
        空间复杂度O(1)
    """

    def maxVowels(self, s: str, k: int) -> int:
        left, right = 0, k - 1
        cnt = sum(1 for ch in s[left : right + 1] if ch in "aeiou")
        ans = cnt
        while right < len(s) - 1:
            if s[left] in "aeiou":
                cnt -= 1
            if s[right + 1] in "aeiou":
                cnt += 1
            ans = max(ans, cnt)
            left += 1
            right += 1
        return ans


print(Solution().maxVowels("abciiidef", 3))
