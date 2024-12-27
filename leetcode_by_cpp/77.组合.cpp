/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (74.57%)
 * Likes:    340
 * Dislikes: 0
 * Total Accepted:    74.5K
 * Total Submissions: 99.7K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;

public:
    void backtrack(vector<int> &v, int begin, int n, int k)
    {
        if (v.size() == k)
        {
            res.push_back(v);
            return;
        }
        for (int i = begin; i <= n - (k - v.size()) + 1; i++) 
        //搜索起点的上界 + 接下来要选择的元素个数 - 1 = n
        {
            v.push_back(i);
            backtrack(v, i + 1, n, k);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> v;
        backtrack(v, 1, n, k);
        return res;
    }
};
// @lc code=end
