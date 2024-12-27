/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 *
 * https://leetcode-cn.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (52.16%)
 * Likes:    286
 * Dislikes: 0
 * Total Accepted:    41.8K
 * Total Submissions: 74.5K
 * Testcase Example:  '["i", "love", "leetcode", "i", "love", "coding"]\n2'
 *
 * 给一非空的单词列表，返回前 k 个出现次数最多的单词。
 * 
 * 返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
 * 
 * 示例 1：
 * 
 * 
 * 输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * 输出: ["i", "love"]
 * 解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
 * ⁠   注意，按字母顺序 "i" 在 "love" 之前。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"],
 * k = 4
 * 输出: ["the", "is", "sunny", "day"]
 * 解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
 * ⁠   出现次数依次为 4, 3, 2 和 1 次。
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
 * 输入的单词均由小写字母组成。
 * 
 * 
 * 
 * 
 * 扩展练习：
 * 
 * 
 * 尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        vector<string> res(k);
        unordered_map<string, int> umap;
        for (auto &w : words)
            umap[w]++;
        vector<string> t;
        for (auto &m : umap)
            t.push_back(m.first);
        sort(t.begin(), t.end(), [&](const auto &a, const auto &b)
             { return umap[a] == umap[b] ? a < b : umap[a] > umap[b]; });
        return vector<string>(t.begin(), t.begin() + k);
        /* 
        auto cmp = [](const pair<int, string> &a, const pair<int, string> &b)
        {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        };
        priority_queue < pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pri_q(cmp);
        for (auto &[key, value] : umap)
        {
            pri_q.push({value, key});
            if (pri_q.size() > k)
                pri_q.pop();
        }
        while (!pri_q.empty())
        {
            res[--k] = pri_q.top().second;
            pri_q.pop();
        }
        return res;
        */
    }
};
// @lc code=end
