/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 *
 * https://leetcode-cn.com/problems/predict-the-winner/description/
 *
 * algorithms
 * Medium (52.75%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    22.2K
 * Total Submissions: 39.1K
 * Testcase Example:  '[1,5,2]'
 *
 * 给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，然后玩家 1 拿，……
 * 。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。
 * 
 * 给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1, 5, 2]
 * 输出：False
 * 解释：一开始，玩家1可以从1和2中进行选择。
 * 如果他选择 2（或者 1 ），那么玩家 2 可以从 1（或者 2 ）和 5 中进行选择。如果玩家 2 选择了 5 ，那么玩家 1 则只剩下 1（或者 2
 * ）可选。
 * 所以，玩家 1 的最终分数为 1 + 2 = 3，而玩家 2 为 5 。
 * 因此，玩家 1 永远不会成为赢家，返回 False 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：[1, 5, 233, 7]
 * 输出：True
 * 解释：玩家 1 一开始选择 1 。然后玩家 2 必须从 5 和 7 中进行选择。无论玩家 2 选择了哪个，玩家 1 都可以选择 233 。
 * ⁠    最终，玩家 1（234 分）比玩家 2（12 分）获得更多的分数，所以返回 True，表示玩家 1 可以成为赢家。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= 给定的数组长度 <= 20.
 * 数组里所有分数都为非负数且不会大于 10000000 。
 * 如果最终两个玩家的分数相等，那么玩家 1 仍为赢家。
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
private:
    int getScore(vector<int> &nums, int start, int end)
    {
        int selectLeft, selectRight;
        int gap = end - start;
        if (gap == 0)
        {
            return nums[start];
        }
        else if (gap == 1)
        { // 此时直接取左右的值就可以
            selectLeft = nums[start];
            selectRight = nums[end];
        }
        else if (gap >= 2)
        { // 如果gap大于2，递归计算selectLeft和selectRight
            // 计算的过程为什么用min，因为要按照对手也是最聪明的来计算。
            int num = getScore(nums, start + 1, end - 1);
            selectLeft = nums[start] +
                         min(getScore(nums, start + 2, end), num);
            selectRight = nums[end] +
                          min(num, getScore(nums, start, end - 2));
        }
        return max(selectLeft, selectRight);
    }

public:
    bool PredictTheWinner(vector<int> &nums)
    {
        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }
        int player1 = getScore(nums, 0, nums.size() - 1);
        int player2 = sum - player1;
        // 如果最终两个玩家的分数相等，那么玩家 1 仍为赢家，所以是大于等于。
        return player1 >= player2;
    }
};
// @lc code=end
