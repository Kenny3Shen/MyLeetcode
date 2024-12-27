/*
 * @lc app=leetcode.cn id=1566 lang=cpp
 *
 * [1566] 重复至少 K 次且长度为 M 的模式
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool containsPattern(vector<int> &arr, int m, int k)
    {
        int cnt = 1, j = 0; //cnt从 1开始，第一次匹配有两个模式串
        for (int i = 0; i + m < arr.size(); i++) //sliding window --> i + m
        {
            if (arr[i] != arr[i + m])
            {
                cnt = 1;
                j = 0;
                continue;
            }
            else
                j++;
            if (j % m == 0)
            {
                cnt++;
                if (cnt == k)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
