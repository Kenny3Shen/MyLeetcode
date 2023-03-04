/*
 * @lc app=leetcode.cn id=2558 lang=cpp
 *
 * [2558] 从数量最多的堆取走礼物
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int, vector<int>, less<int>> pq(gifts.begin(), gifts.end());
        while (k--)
        {
            int t = pq.top();
            pq.pop();   
            pq.push(sqrt(t));
        }
        long long res = 0;
        while (!pq.empty())
        {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
