/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (79.42%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    32.6K
 * Total Submissions: 40.9K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 * [".Q..",  // 解法 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // 解法 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一或
 * N-1 步，可进可退。（引用自 百度百科 - 皇后 ）
 * 
 * 
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
private:
    int res = 0;
    vector<int> cols;

public:
    bool isValid(int n)
    {
        if (cols.size() <= 1)
            return true;
        int row = cols.size() - 1; //前 m - 1 行
        int col = cols.back();  //第 m 行
        for (int r = 0; r < row; ++r)
        {
            int c = cols[r];
            if (c == col || abs(c - col) == abs(r - row))
                //同一列  || 对角线
                return false;
        }
        return true;
    }

    void backtrack(int n)
    {
        if (!isValid(n))
            return;

        if (cols.size() == n)
        {
            res++;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            cols.push_back(i);  //列向量位置
            backtrack(n);
            cols.pop_back(); //backtrack
        }
    }

    int totalNQueens(int n)
    {
        backtrack(n);
        return res;
    }
};
// @lc code=end
