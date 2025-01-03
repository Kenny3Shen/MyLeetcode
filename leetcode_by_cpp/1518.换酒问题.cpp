/*
 * @lc app=leetcode.cn id=1518 lang=cpp
 *
 * [1518] 换酒问题
 *
 * https://leetcode-cn.com/problems/water-bottles/description/
 *
 * algorithms
 * Easy (69.23%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    10.3K
 * Total Submissions: 14.9K
 * Testcase Example:  '9\n3'
 *
 * 小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。你购入了 numBottles 瓶酒。
 * 
 * 如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。
 * 
 * 请你计算 最多 能喝到多少瓶酒。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：numBottles = 9, numExchange = 3
 * 输出：13
 * 解释：你可以用 3 个空酒瓶兑换 1 瓶酒。
 * 所以最多能喝到 9 + 3 + 1 = 13 瓶酒。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：numBottles = 15, numExchange = 4
 * 输出：19
 * 解释：你可以用 4 个空酒瓶兑换 1 瓶酒。
 * 所以最多能喝到 15 + 3 + 1 = 19 瓶酒。
 * 
 * 
 * 示例 3：
 * 
 * 输入：numBottles = 5, numExchange = 5
 * 输出：6
 * 
 * 
 * 示例 4：
 * 
 * 输入：numBottles = 2, numExchange = 3
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= numBottles <= 100
 * 2 <= numExchange <= 100
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        /* int totalBottles = numBottles;
        int remiander = numBottles;
        while (1)
        {
            int canExchange = remiander / numExchange;
            totalBottles += canExchange;
            remiander %= numExchange;
            remiander += canExchange;
            if (remiander < numExchange)
                break;
        }
        return totalBottles; */

        return (numBottles * numExchange - 1) / (numExchange - 1);
        //一个空瓶价值为1的话，
        //numBottles * numExchange为总价值，
        //至少一个空瓶最后留在手里换不了，所以总价值-1，numExchange-1为一份酒的价值,。
    }
};
// @lc code=end
