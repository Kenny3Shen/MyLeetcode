/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 *
 * https://leetcode-cn.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (67.54%)
 * Likes:    264
 * Dislikes: 0
 * Total Accepted:    49.9K
 * Total Submissions: 73.7K
 * Testcase Example:  '"tree"'
 *
 * 给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * "tree"
 * 
 * 输出:
 * "eert"
 * 
 * 解释:
 * 'e'出现两次，'r'和't'都只出现一次。
 * 因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * "cccaaa"
 * 
 * 输出:
 * "cccaaa"
 * 
 * 解释:
 * 'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
 * 注意"cacaca"是不正确的，因为相同的字母必须放在一起。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入:
 * "Aabb"
 * 
 * 输出:
 * "bbAa"
 * 
 * 解释:
 * 此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
 * 注意'A'和'a'被认为是两种不同的字符。
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> umap;
        for (auto &c : s)
            umap[c]++;
        vector<pair<char, int>> v(umap.begin(), umap.end());
        sort(v.begin(), v.end(),[](auto &a, auto &b){
            return a.second > b.second;
        });
        string res{};
        for(auto &i : v)
        {
            string t(i.second, i.first);
            res += t;
        }
        return res;
    }
};
// @lc code=end
