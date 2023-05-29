/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (48.08%)
 * Likes:    885
 * Dislikes: 0
 * Total Accepted:    154.5K
 * Total Submissions: 321.3K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * 
 */

// @lc code=start
#include<vector> 
using namespace std;
class Solution
{
public:
    /*int cnt = 0;
    void dp(int n)
    {
        if (n > 0)
        {
            dp(n - 1);
            if(n-2 < 0)
                return;
            else
                dp(n-2);       
        }
        if (n == 0)
            cnt++;
        return;
    }*/
    int climbStairs(int n)
    {
        vector<int>dp(4,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=n;i++)
        {
            //在dp的最后一个向量后插入一个元素，其值为0
            dp.push_back(0);
            dp[i]=dp[i-1]+dp[i-2]; //f(n)=f(n-1)+f(n-2) //类斐波那契数列
        }
        return dp[n];
    }
};
// @lc code=end
