/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 */
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> sum(size, 0);          //前缀和数组
        unordered_map<int, int> thisIndex; //记录当前数字上一次出现的下标
        int first = 0, curSum = 0, curMax = 0;
        sum[0] = nums[0];
        thisIndex[nums[0]] = 0;
        for (int i = 1; i < size; i++)
        {
            if (thisIndex.find(nums[i]) != thisIndex.end() && thisIndex[nums[i]] >= first)
            { //当前数字出现过，且该数字的下标大于该连续子串的开头下标，即此时连续子串中某数出现第二次
                curSum = sum[i - 1] - sum[first] + nums[first];
                curMax = max(curSum, curMax);
                first = thisIndex[nums[i]] + 1;
            }
            thisIndex[nums[i]] = i; //更新出现数字的最新下标
            sum[i] = sum[i - 1] + nums[i];
        }
        //连续子串出现在最末尾，最后一次最大判断，同时也表示了curSum至少会更新一次
        curSum = sum[size - 1] - sum[first] + nums[first];
        curMax = max(curSum, curMax);
        return curMax;
    }
};
// @lc code=end
