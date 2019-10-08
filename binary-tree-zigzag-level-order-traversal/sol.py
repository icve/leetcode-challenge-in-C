# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        zig = True
        i = 0
        rlt = []
        while True:
            cur_rlt = self.copyLevel(root, i, zig)
            if cur_rlt:
                rlt.append(cur_rlt)
            else:
                break
            i += 1
            zig = not zig
        return rlt
    
    def copyLevel(self, root, depth, leftFirst=True):
        if root is None: return []
        elif depth == 0: return [root.val]
        cp_helper = lambda r: self.copyLevel(r, depth-1, leftFirst)
        if leftFirst:
            return cp_helper(root.left) + cp_helper(root.right)
        else:
            return cp_helper(root.right) + cp_helper(root.left)