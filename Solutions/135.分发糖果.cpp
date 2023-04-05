/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> candies(ratings.size(), 1);

        //从前往后遍历，左相邻比较
        for (int i = 1; i < ratings.size(); i++)
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;

        //从后往前遍历，右相邻比较
        for (int i = ratings.size() - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);

        return accumulate(candies.begin(), candies.end(), 0);
    }
};
// @lc code=end
