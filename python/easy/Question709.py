class Solution:
    """
    方法二：手动实现该API，有压行技巧
    """

    def toLowerCase(self, s: str) -> str:
        return "".join(
            chr(asc | 32) if 65 <= (asc := ord(ch)) <= 90 else ch for ch in s
        )

    """
    方法一：直接调用API
    """

    # def toLowerCase(self, s: str) -> str:
    #     return s.lower()


print(Solution().toLowerCase("Hello"))
