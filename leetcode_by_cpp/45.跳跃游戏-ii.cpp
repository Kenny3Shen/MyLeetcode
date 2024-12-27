/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int res = 0;
        int curJump = 0;
        int nextJump = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            nextJump = max(nextJump, nums[i] + i);
            if (i == curJump) // i 在[0,n - 2]时都要再走下一步，i == n-1时说明curJump >= nums.size() - 1
            {
                curJump = nextJump;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
