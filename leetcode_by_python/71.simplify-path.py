#
# @lc app=leetcode.cn id=71 lang=python3
# @lcpr version=30204
#
# [71] 简化路径
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def simplifyPath(self, path: str) -> str:
        st = []
        for p in path.split('/'):
            if p == "" or p == ".":
                continue
            elif p == "..":
                if st:
                    st.pop()
            else:
                st.append(p)
        return '/' + '/'.join(st)
# @lc code=end



#
# @lcpr case=start
# "/home/"\n
# @lcpr case=end

# @lcpr case=start
# "/home//foo/"\n
# @lcpr case=end

# @lcpr case=start
# "/home/user/Documents/../Pictures"\n
# @lcpr case=end

# @lcpr case=start
# "/../"\n
# @lcpr case=end

# @lcpr case=start
# "/.../a/../b/c/../d/./"\n
# @lcpr case=end

#

