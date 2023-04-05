/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode-cn.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (38.56%)
 * Likes:    289
 * Dislikes: 0
 * Total Accepted:    69.7K
 * Total Submissions: 169.8K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 * 
 * 换句话说，第一个字符串的排列之一是第二个字符串的子串。
 * 
 * 示例1:
 * 
 * 
 * 输入: s1 = "ab" s2 = "eidbaooo"
 * 输出: True
 * 解释: s2 包含 s1 的排列之一 ("ba").
 * 
 * 
 * 
 * 
 * 示例2:
 * 
 * 
 * 输入: s1= "ab" s2 = "eidboaoo"
 * 输出: False
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 输入的字符串只包含小写字母
 * 两个字符串的长度都在 [1, 10,000] 之间
 * 
 * 
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        // 排除异常的边界情况，也限定了模式串的长度
        if (s1.size() > s2.size())
            return false;
        // 匹配采用的窗口大小为模式串大小
        int windowSize = s1.size();
        // 模式串的字典：可以看做一种频率分布
        vector<int> hashmap1(26, 0);
        // 动态更新的匹配窗口字典
        vector<int> hashmap2(26, 0);
        // 构建字典
        for (int i = 0; i < windowSize; i++)
        {
            hashmap1[s1[i] - 'a']++;
            hashmap2[s2[i] - 'a']++;
        }
        // 对于每一轮滑窗查询，如果两个字典相等(频率分布一致)，则命中
        for (int i = windowSize; i < s2.size(); i++)
        {
            // 两个字典相等(频率分布一致)，则命中
            if (hashmap1 == hashmap2)
                return true;
            // 否则，向右滑窗：滑窗对于 hash 表的操作变为对应频率的增减
            hashmap2[s2[i - windowSize] - 'a']--;
            hashmap2[s2[i] - 'a']++;
        }
        // 整个算法采用左闭右开区间，因此最后还有一个窗口没有判断
        return hashmap1 == hashmap2;
        /* unordered_map<char, int> cnt1, cnt2;
        for (const char &c : s1)
            cnt1[c]++;
        if (s1.size() > s2.size())
            return false;
        int i = 0, j = s1.size() - 1;
        for (int k = 0; k <= j; k++)
            cnt2[s2[k]]++;
        while (j < s2.size())
        {
            if (cnt1 == cnt2)
                return true;
            else
            {
                cnt2[s2[i]]--;
                if (cnt2[s2[i]] == 0)
                    cnt2.erase(cnt2.find(s2[i]));
                i++;
                j++;
                cnt2[s2[j]]++;
            }
        }
        return false; */
    }
};
// @lc code=end
