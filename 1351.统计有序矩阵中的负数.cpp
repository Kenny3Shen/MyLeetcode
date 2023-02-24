/*
 * @lc app=leetcode.cn id=1351 lang=cpp
 *
 * [1351] 统计有序矩阵中的负数
 *
 * https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
 *
 * algorithms
 * Easy (77.57%)
 * Likes:    36
 * Dislikes: 0
 * Total Accepted:    15.3K
 * Total Submissions: 20.1K
 * Testcase Example:  '[[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]'
 *
 * 给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 
 * 
 * 请你统计并返回 grid 中 负数 的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：grid = [[4,3,2,-1],[3,2,1,-],[1,1,-1,-2],[-1,-1,-2,-3]]
 * 输出：8
 * 解释：矩阵中共有 8 个负数。
 *
 *
 *示例 2：
 * 
 * 输入：grd = [[3,2],[1,0]]
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 输入：grid = [[1,-1],[-1,-1]]
 * 输出：3
 * 
 * 
 * 示例 4：
 * 
 * 输入：grid = [[1]] * 输出：1
 * 
 * 
  
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n = gri[i].length
 * 1 <= , n <= 100
 * -100 <= grid[i][j] <= 100
 * 
 * 
 */
//@lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            ans += count_if(grid[i].begin(),grid[i].end(),
                    [](int x){return x < 0;});  //lambda function
        }
        return ans;
    }
};
/* 
[] 不捕获任何变量
[&] 以引用方式捕获所有变量
[=] 用值的方式捕获所有变量（可能被编译器优化为const &)
[=, &foo] 以引用捕获foo, 但其余变量都靠值捕获
[&, foo] 以值捕获foo, 但其余变量都靠引用捕获
[bar] 以值方式捕获bar; 不捕获其它变量
[this] 捕获所在类的this指针 
*/
// @lc code=end
 
