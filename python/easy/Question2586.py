from typing import List


class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        ans = 0
        for s in words[left : right + 1]:
            # if (
            #     s[0] == "a" or s[0] == "e" or s[0] == "i" or s[0] == "o" or s[0] == "u"
            # ) and (
            #     s[-1] == "a"
            #     or s[-1] == "e"
            #     or s[-1] == "i"
            #     or s[-1] == "o"
            #     or s[-1] == "u"
            # ):
            # 使用in运算符可以压行
            if s[0] in "aeiou" and s[-1] in "aeiou":
                ans += 1
        return ans
