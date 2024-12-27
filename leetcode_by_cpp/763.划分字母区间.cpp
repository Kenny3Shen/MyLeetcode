/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 *
 * https://leetcode-cn.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (72.50%)
 * Likes:    357
 * Dislikes: 0
 * Total Accepted:    44.1K
 * Total Submissions: 57.7K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：S = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 * 解释：
 * 划分结果为 "ababcbaca", "defegde", "hijhklij"。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * S的长度在[1, 500]之间。
 * S只包含小写字母 'a' 到 'z' 。
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
    vector<int> partitionLabels(string S)
    {
        vector<int> res;
        int hash[26] = {0};
        for (int i = 0; i < S.size(); i++)
            hash[S[i] - 'a'] = i; //记录每个字符出现的最后位置

        int left = 0, right = 0;
        for (int i = 0; i < S.size(); i++)
        {
            right = max(right, hash[S[i] - 'a']); //贪心算法
            if (i == right)                       //找到 i之前出现过的字符的最远边界
            {
                res.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return res;
    }
};
// @lc code=end
