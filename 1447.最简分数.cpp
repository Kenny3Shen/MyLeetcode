/*
 * @lc app=leetcode.cn id=1447 lang=cpp
 *
 * [1447] 最简分数
 *
 * https://leetcode-cn.com/problems/simplified-fractions/description/
 *
 * algorithms
 * Medium (62.01%)
 * Likes:    7
 * Dislikes: 0
 * Total Accepted:    3.8K
 * Total Submissions: 6.1K
 * Testcase Example:  '2'
 *
 * 给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。分数可以以 任意 顺序返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 2
 * 输出：["1/2"]
 * 解释："1/2" 是唯一一个分母小于等于 2 的最简分数。
 * 
 * 示例 2：
 * 
 * 输入：n = 3
 * 输出：["1/2","1/3","2/3"]
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 4
 * 输出：["1/2","1/3","1/4","2/3","3/4"]
 * 解释："2/4" 不是最简分数，因为它可以化简为 "1/2" 。
 * 
 * 示例 4：
 * 
 * 输入：n = 1
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 100
 * 
 * 
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int GCD(int a, int b)
    {
        while (b)
        {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    vector<string> simplifiedFractions(int n)
    {
        vector<string> res;
        if (n == 1)
            return res;
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j < n + 1; j++)
                if (GCD(i, j) == 1)
                    res.push_back(to_string(i) + "/" + to_string(j));
        return res;
    }
};
// @lc code=end
