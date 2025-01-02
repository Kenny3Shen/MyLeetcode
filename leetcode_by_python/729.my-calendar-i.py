#
# @lc app=leetcode.cn id=729 lang=python3
# @lcpr version=30204
#
# [729] 我的日程安排表 I
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
from sortedcontainers import SortedDict


class MyCalendar:

    def __init__(self):
        self.sd = SortedDict()

    def book(self, start: int, end: int) -> bool:
        idx = self.sd.bisect_right(start)
        if idx < len(self.sd) and self.sd.values()[idx] < end:
            return False
        self.sd[end] = start
        return True
        


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(startTime,endTime)
# @lc code=end



#
# @lcpr case=start
# ["MyCalendar", "book", "book", "book"][[], [10, 20], [15, 25], [20, 30]]\n
# @lcpr case=end

#

