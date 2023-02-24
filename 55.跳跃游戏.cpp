/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return true;
        
        int span = 0;
        for(int i = 0; i <= span; i++) //i 只能在目前最大范围活动
        {
            span = max(span, nums[i] + i);
            if(span >= nums.size() - 1)
                return true;
        }
        return false;
    }
};
// @lc code=end

