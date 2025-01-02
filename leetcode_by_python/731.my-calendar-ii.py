#
# @lc app=leetcode.cn id=731 lang=python3
# @lcpr version=30204
#
# [731] 我的日程安排表 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
MAX = int(1e9)
class MyCalendarTwo:

    def __init__(self):
        self.rt = SegmentTree().root

    def book(self, start: int, end: int) -> bool:
        if SegmentTree.query(self.rt, 0, MAX, start, end - 1) < 2:
            SegmentTree.update(self.rt, 0, MAX, start, end - 1, 1)
            return True
        return False


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)


class Node:
    def __init__(self) -> None:
        self.ls = self.rs = None
        self.val = self.add = 0

class SegmentTree:
    def __init__(self):
        self.root = Node()
    
    @staticmethod
    def update(node: Node, lc: int, rc: int, l: int, r: int, v: int) -> None:
        if l <= lc and rc <= r:
            node.add += v
            node.val += v
            return
        SegmentTree.pushdown(node)
        mid = (lc + rc) >> 1
        if l <= mid:
            SegmentTree.update(node.ls, lc, mid, l, r, v)
        if r > mid:
            SegmentTree.update(node.rs, mid + 1, rc, l, r, v)
        SegmentTree.pushup(node)
 
    @staticmethod
    def query(node: Node, lc: int, rc: int, l: int, r: int) -> int:
        if l <= lc and rc <= r:
            return node.val
        # 先确保所有关联的懒标记下沉下去
        SegmentTree.pushdown(node)
        mid, ans = (lc + rc) >> 1, 0
        if l <= mid:
            ans = SegmentTree.query(node.ls, lc, mid, l, r)
        if r > mid:
            # 同样为不同题目中的更新方式
            ans = max(ans, SegmentTree.query(node.rs, mid + 1, rc, l, r))
        return ans
    
    @staticmethod
    def pushdown(node: Node) -> None:
        # 懒标记, 在需要的时候才开拓节点和赋值
        if node.ls is None:
            node.ls = Node()
        if node.rs is None:
            node.rs = Node()
        if not node.add:
            return
        node.ls.add += node.add
        node.rs.add += node.add
        node.ls.val += node.add
        node.rs.val += node.add
        node.add = 0
    
    @staticmethod
    def pushup(node: Node) -> None:
        # 动态更新方式：此处为最大值
        node.val = max(node.ls.val, node.rs.val)
# @lc code=end



#
# @lcpr case=start
# ["MyCalendarTwo", "book", "book", "book", "book", "book", "book"][[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]\n
# @lcpr case=end

#

