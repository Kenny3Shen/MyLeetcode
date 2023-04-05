/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        long long maxi = 1, res = 0, i = 0;
        while (maxi <= n)
        {
            if (i < nums.size() && nums[i] <= maxi)
                maxi += nums[i++];
            else
                maxi += maxi, res++;
        }
        return res;
    }
};
/* 核心逻辑：[0,x) 的若干个数加上 k，可扩大值域至 [0,x+k)，注意 k∈[0,x]。
将 k 视为 nums已有的数 或者 要插入的数
根据题意，nums 必须有 1
显然从 [0,1) 开始模拟扩展，一般地，我们取 k 最大，也就是 k = x
假设 nums 空，我们这样模拟 [0,1) -> [0,2) -> [0,4) -> [0,8) ----> [0,y)，直到 y > n
因此当 nums(i) ∈ [0,y] 时，可取之为 k 并扩大值域， 否则视为插入一个数 y。 */
// @lc code=end
