from collections import defaultdict


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = left = 0
        # 哈希表写法
        # cnt = defaultdict(int)
        # for right, ch in enumerate(s):
        #     cnt[ch] += 1
        #     while cnt[ch] > 1:
        #         cnt[s[left]] -= 1
        #         left += 1

        # 哈希集合写法
        window = set()
        for right, ch in enumerate(s):
            # 要先删再加，否则无法识别出重复
            while ch in window:
                window.remove(s[left])
                left += 1
            window.add(ch)
            ans = max(ans, right - left + 1)
        return ans


print(Solution().lengthOfLongestSubstring("abcabcbb"))
