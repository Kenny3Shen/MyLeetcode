/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (42.36%)
 * Likes:    595
 * Dislikes: 0
 * Total Accepted:    99.9K
 * Total Submissions: 231.4K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool backtrack(vector<vector<char>> &board, string &word, int wordIndex, int x, int y)
    {
        if (board[x][y] != word[wordIndex])
            return false;
        
        if (word.size() - 1 == wordIndex) // end condition
            return true;

        char temp = board[x][y]; //避免该位重复使用
        board[x][y] = '0';        // board 和 word 中只包含大写和小写英文字母

        if ((x > 0 && backtrack(board, word, wordIndex + 1, x - 1, y))                       // 往上走
            || (y > 0 && backtrack(board, word, wordIndex + 1, x, y - 1))                    // 往左走
            || (x < board.size() - 1 && backtrack(board, word, wordIndex + 1, x + 1, y))     // 往下走
            || (y < board[0].size() - 1 && backtrack(board, word, wordIndex + 1, x, y + 1))) // 往右走
        {
            return true; // 其中一条能走通，就算成功
        }

        board[x][y] = temp; // backtrack
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (backtrack(board, word, 0, i, j))
                {
                    return true;    
                }
            }
        }
        return false;
    }
};
// @lc code=end
