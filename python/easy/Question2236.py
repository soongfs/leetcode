from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def checkTree(self, root: Optional[TreeNode]) -> bool:
        return (
            root != None
            and root.left != None
            and root.right != None
            and root.val == root.left.val + root.right.val
        )
