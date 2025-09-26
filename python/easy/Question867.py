from typing import List
import numpy


class Solution:
    """
    方法三：调用标准库的zip()函数
    """

    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        return [list(row) for row in zip(*matrix)]

    """
    方法二：调用numpy现有API
    """

    # def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
    #     return numpy.array(matrix).T.tolist()

    """
    方法一：模拟
        时间复杂度O(m*n)
        空间复杂度O(m*n)
    """

    # def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
    #     m = len(matrix)  # 行
    #     n = len(matrix[0])  # 列
    #     ans = [[0] * m for _ in range(n)]
    #     for i in range(n):
    #         for j in range(m):
    #             ans[i][j] = matrix[j][i]
    #     return ans


matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(Solution().transpose(matrix))
