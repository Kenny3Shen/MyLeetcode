/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 *
 * https://leetcode-cn.com/problems/maximum-score-after-splitting-a-string/description/
 *
 * algorithms
 * Easy (53.14%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    5.8K
 * Total Submissions: 10.9K
 * Testcase Example:  '"011101"'
 *
 * 给你一个由若干 0 和 1 组成的字符串 s ，请你计算并返回将该字符串分割成两个 非空 子字符串（即 左 子字符串和 右
 * 子字符串）所能获得的最大得分。
 * 
 * 「分割字符串的得分」为 左 子字符串中 0 的数量加上 右 子字符串中 1 的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "011101"
 * 输出：5 
 * 解释：
 * 将字符串 s 划分为两个非空子字符串的可行方案有：
 * 左子字符串 = "0" 且 右子字符串 = "11101"，得分 = 1 + 4 = 5 
 * 左子字符串 = "01" 且 右子字符串 = "1101"，得分 = 1 + 3 = 4 
 * 左子字符串 = "011" 且 右子字符串 = "101"，得分 = 1 + 2 = 3 
 * 左子字符串 = "0111" 且 右子字符串 = "01"，得分 = 1 + 1 = 2 
 * 左子字符串 = "01110" 且 右子字符串 = "1"，得分 = 2 + 1 = 3
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "00111"
 * 输出：5
 * 解释：当 左子字符串 = "00" 且 右子字符串 = "111" 时，我们得到最大得分 = 2 + 3 = 5
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "1111"
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= s.length <= 500
 * 字符串 s 仅由字符 '0' 和 '1' 组成。
 * 
 * 
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxScore(string s)
    {
        int leftScore = s[0] == '0';                         //左端长度至少为 1
        int rightScore = count(s.begin() + 1, s.end(), '1'); //右端最大值 1 ~ n - 1
        int max_sum = leftScore + rightScore;                //左 1 右n - 1
        for (int i = 1; i < s.length() - 1; i++)             //求左端+右端最大值(右端长度至少为 1)
        {
            if (s[i] == '0')
                leftScore++;
            if (s[i] == '1')
                rightScore--;
            max_sum = max(max_sum, leftScore + rightScore);
        }
        return max_sum;
    }
};
// @lc code=end
