class Solution:
    """
    方法一：滑动窗口
        时间复杂度O(n)
        空间复杂度O(1)
    """

    def minimumRecolors(self, blocks: str, k: int) -> int:
        n = len(blocks)
        ans = float("inf")
        cnt_w = 0
        for i in range(n):
            if blocks[i] == "W":
                cnt_w += 1
            if i - k + 1 < 0:
                continue
            else:
                ans = min(ans, cnt_w)
                if blocks[i - k + 1] == "W":
                    cnt_w -= 1
        return int(ans)


print(Solution().minimumRecolors("WBBWWBBWBW", 7))
