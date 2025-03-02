#
# @lc app=leetcode.cn id=79 lang=python3
# @lcpr version=30204
#
# [79] 单词搜索
#


# @lcpr-template-start
from typing import List
from collections import Counter


# @lcpr-template-end
# @lc code=start
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        cnt = Counter([c for row in board for c in row])
        # 如果 board 中的字母不够，直接返回 False
        if cnt < Counter(word):
            return False
        # 如果 word 以 a 开头，以 d 结尾, 但 board 中的 a 很多，d 很少（比如只有一个）
        # 那么从 d 开始搜索，能更快地找到答案。（即使我们肉眼去找，这种方法也是更快的）
        if cnt[word[-1]] < cnt[word[0]]:
            word = word[::-1]

        m, n = len(board), len(board[0])

        def dfs(i, j, k):
            if board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True
            
            board[i][j] = ""
            for x, y in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                if 0 <= x < m and 0 <= y < n and dfs(x, y, k + 1):
                    return True
            board[i][j] = word[k]
            return False

        return any(dfs(i, j, 0) for i in range(m) for j in range(n))


# @lc code=end


#
# @lcpr case=start
# [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
# @lcpr case=end

# @lcpr case=start
# [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
# @lcpr case=end

# @lcpr case=start
# [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
# @lcpr case=end

#
