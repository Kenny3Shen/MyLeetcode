/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 *
 * https://leetcode-cn.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (54.37%)
 * Likes:    55
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 19.8K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold
 * Medal", "Silver Medal", "Bronze Medal"）。
 * 
 * (注：分数越高的选手，排名越靠前。)
 * 
 * 示例 1:
 * 
 * 
 * 输入: [5, 4, 3, 2, 1]
 * 输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * 解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal"
 * and "Bronze Medal").
 * 余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
 * 
 * 提示:
 * 
 * 
 * N 是一个正整数并且不会超过 10000。
 * 所有运动员的成绩都不相同。
 * 
 * 
 */
#include <vector>
#include <map>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &a)
    {
        map<int, int> m;
        vector<string> res(a.size());
        for (int i = 0; i < a.size(); i++)
            m[a[i]] = i; //map(RB-tree) 具有排序性 ,对 key排序，data为下标

        auto it = m.rbegin();   

        res[it++->second] = "Gold Medal";
        if (it != m.rend())
            res[it++->second] = "Silver Medal";
        if (it != m.rend())
            res[it++->second] = "Bronze Medal";
        
        int j = 4;
        for (; it != m.rend(); it++, j++)
            res[it->second] = to_string(j);
        return res;
    }
};
// @lc code=end
