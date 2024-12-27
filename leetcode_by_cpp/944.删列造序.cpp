/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minDeletionSize(vector<string> &A)
    {
        int res = 0;
        for (int i = 0; i < A[0].size(); i++)
        {
            for (int j = 1; j < A.size(); j++)
            {
                if (A[j][i] < A[j - 1][i])
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
