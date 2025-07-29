class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        if word.isalnum() == False:
            return False
        inc_vowel = False
        inc_consonant = False
        for ch in word:
            if ch in "aeiouAEIOU":
                inc_vowel = True
            elif ch not in "aeiouAEIOU" and ch.isalpha():
                inc_consonant = True
        return inc_vowel and inc_consonant


print(Solution().isValid("b31a)"))
