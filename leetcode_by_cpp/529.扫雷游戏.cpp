/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 *
 * https://leetcode-cn.com/problems/minesweeper/description/
 *
 * algorithms
 * Medium (60.55%)
 * Likes:    118
 * Dislikes: 0
 * Total Accepted:    16.5K
 * Total Submissions: 25.9K
 * Testcase Example:  '[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]\n' +
  '[3,0]'
 *
 * 让我们一起来玩扫雷游戏！
 * 
 * 给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B'
 * 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X'
 * 则表示一个已挖出的地雷。
 * 
 * 现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
 * 
 * 
 * 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
 * 如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
 * 如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
 * 如果在此次点击中，若无更多方块可被揭露，则返回面板。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: 
 * 
 * [['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'M', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E']]
 * 
 * Click : [3,0]
 * 
 * 输出: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * 解释:
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Click : [1,2]
 * 
 * 输出: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'X', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * 解释:
 * 
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 输入矩阵的宽和高的范围为 [1,50]。
 * 点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。
 * 输入面板不会是游戏结束的状态（即有地雷已被挖出）。
 * 简单起见，未提及的规则在这个问题中可被忽略。例如，当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
private: //      从左上方顺时针遍历方格四周
    int d_x[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int d_y[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

public:
    void DFS_digging(vector<vector<char>> &board, int x, int y)
    {
        int mine = 0;
        for (int i = 0; i < 8; i++) //查看点击方格四周是否有地雷
        {
            int tx = x + d_x[i], ty = y + d_y[i];
            if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()) //越界判断
                continue;
            if (board[tx][ty] == 'M') //该点击方格的四周有雷
                mine++;
        }
        if (mine > 0)
            board[x][y] = mine + '0'; //修改方格为四周地雷的总数
        else                          //无地雷则更新为 'B' 并向四周递归挖掘
        {
            board[x][y] = 'B';
            for (int i = 0; i < 8; i++)
            {
                int tx = x + d_x[i], ty = y + d_y[i];
                if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E')
                    continue; //越界 or 该方格为地雷 or 该方格以被挖掘
                DFS_digging(board, tx, ty);
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int row = click[0], col = click[1];
        if (board[row][col] == 'M')
            board[row][col] = 'X';
        else
            DFS_digging(board, row, col);
        return board;
    }
};
// @lc code=end
