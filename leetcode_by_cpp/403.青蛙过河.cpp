/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 *
 * https://leetcode-cn.com/problems/frog-jump/description/
 *
 * algorithms
 * Hard (39.96%)
 * Likes:    284
 * Dislikes: 0
 * Total Accepted:    30.8K
 * Total Submissions: 70.6K
 * Testcase Example:  '[0,1,3,5,6,8,12,17]'
 *
 * 一只青蛙想要过河。 假定河流被等分为若干个单元格，并且在每一个单元格内都有可能放有一块石子（也有可能没有）。 青蛙可以跳上石子，但是不可以跳入水中。
 * 
 * 给你石子的位置列表 stones（用单元格序号 升序 表示）， 请判定青蛙能否成功过河（即能否在最后一步跳至最后一块石子上）。
 * 
 * 开始时， 青蛙默认已站在第一块石子上，并可以假定它第一步只能跳跃一个单位（即只能从单元格 1 跳至单元格 2 ）。
 * 
 * 如果青蛙上一步跳跃了 k 个单位，那么它接下来的跳跃距离只能选择为 k - 1、k 或 k + 1 个单位。
 * 另请注意，青蛙只能向前方（终点的方向）跳跃。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：stones = [0,1,3,5,6,8,12,17]
 * 输出：true
 * 解释：青蛙可以成功过河，按照如下方案跳跃：跳 1 个单位到第 2 块石子, 然后跳 2 个单位到第 3 块石子, 接着 跳 2 个单位到第 4 块石子,
 * 然后跳 3 个单位到第 6 块石子, 跳 4 个单位到第 7 块石子, 最后，跳 5 个单位到第 8 个石子（即最后一块石子）。
 * 
 * 示例 2：
 * 
 * 
 * 输入：stones = [0,1,2,3,4,8,9,11]
 * 输出：false
 * 解释：这是因为第 5 和第 6 个石子之间的间距太大，没有可选的方案供青蛙跳跃过去。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * 0 
 * stones[0] == 0
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        if (stones[1] != 1)
            return false;
        map<int, int> mp;
        map<int, bool> f; //记忆化cache
        for (int i = 0; i < n; i++)
            mp[stones[i]] = i;

        std::function<bool(int, int)> dfs = [&](int idx, int k) {
            auto key = idx * 10000 + k; //key值可以这样映射
            if (f.count(key))
                return f[key];
            if (idx == n - 1)
                return true;
            for (int i = -1; i <= 1; i++)
            {
                if (k + i == 0)
                    continue;
                int next = stones[idx] + k + i;
                if (mp.count(next))
                {
                    bool cur = dfs(mp[next], k + i);
                    f[key] = cur;
                    if (cur)
                        return true;
                }
            }
            f[key] = false;
            return false;
        };

        return dfs(1, 1);
    }
};
// @lc code=end
