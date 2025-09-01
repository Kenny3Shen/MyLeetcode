#
# @lc app=leetcode.cn id=36 lang=python3
# @lcpr version=30204
#
# [36] 有效的数独
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_set = [set() for _ in range(9)]
        col_set = [set() for _ in range(9)]
        box_set = [set() for _ in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] == ".":
                    continue
                if (
                    board[i][j] in row_set[i]
                    or board[i][j] in col_set[j]
                    or board[i][j] in box_set[(i // 3) * 3 + j // 3]
                ):
                    return False
                row_set[i].add(board[i][j])
                col_set[j].add(board[i][j])
                box_set[(i // 3) * 3 + j // 3].add(board[i][j])

        return True


# @lc code=end


#
# @lcpr case=start
# [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
# @lcpr case=end

# @lcpr case=start
# [["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
# @lcpr case=end

#
