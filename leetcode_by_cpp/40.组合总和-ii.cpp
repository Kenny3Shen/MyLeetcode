/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (62.53%)
 * Likes:    350
 * Dislikes: 0
 * Total Accepted:    82K
 * Total Submissions: 130.7K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> combination;

public:
    void DFS(vector<int> &candidates, int target, int begin)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i < candidates.size(); i++)
        {
            if (target - candidates[i] < 0) //必须为有序数组才可提前剪枝
                return;
            if (i > begin && candidates[i] == candidates[i - 1]) //在一层里面只用一次这个数字
                continue;
            combination.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], i + 1);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        DFS(candidates, target, 0);
        return res;
    }
};
// @lc code=end
