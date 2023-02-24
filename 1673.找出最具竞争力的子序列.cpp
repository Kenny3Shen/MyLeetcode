/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 *
 * [1673] 找出最具竞争力的子序列
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        int popCount = nums.size() - k; //最大pop次数，超过这个次数则无法找到长度为 K的子序列
        vector<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            while(!st.empty() && nums[i] < st.back() && popCount != 0)
            {
                st.pop_back();
                popCount--;
            }
              
            st.push_back(nums[i]);
        }
        while(st.size() > k) //长度大于 K部分都是递增的，取前 K个则为最优
            st.pop_back(); 
        return st;
    }
};
// @lc code=end
