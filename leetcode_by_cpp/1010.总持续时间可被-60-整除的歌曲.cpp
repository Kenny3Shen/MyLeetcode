/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 *
 * https://leetcode-cn.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/
 *
 * algorithms
 * Easy (43.56%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    15.3K
 * Total Submissions: 35.2K
 * Testcase Example:  '[30,20,150,100,40]'
 *
 * 在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。
 * 
 * 返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望索引的数字 i 和 j 满足  i < j 且有 (time[i] +
 * time[j]) % 60 == 0。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[30,20,150,100,40]
 * 输出：3
 * 解释：这三对的总持续时间可被 60 整数：
 * (time[0] = 30, time[2] = 150): 总持续时间 180
 * (time[1] = 20, time[3] = 100): 总持续时间 120
 * (time[1] = 20, time[4] = 40): 总持续时间 60
 * 
 * 
 * 示例 2：
 * 
 * 输入：[60,60,60]
 * 输出：3
 * 解释：所有三对的总持续时间都是 120，可以被 60 整数。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= time.length <= 60000
 * 1 <= time[i] <= 500
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int res = 0;
        vector<int> reminderCount(60, 0); // 0 ~ 59
        for (auto t : time)
            reminderCount[t % 60]++;
        //排列组合
        res += reminderCount[0] * (reminderCount[0] - 1) /2;      //0或60
        res += reminderCount[30] * (reminderCount[30] - 1) / 2;   //30
        //组合问题
        for (int i = 1; i <= 29; i++)
            res += reminderCount[i] * reminderCount[60 - i];
        return res;
    }
};
// @lc code=end
