/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> res(S.length(), 0);
        // sliding window
        int left = INT32_MAX;
        int right = 0;
        while (right < S.length() && S[right] != C)
            right++;
        for (int i = 0; i < S.length(); i++)
        {
            res[i] = min(abs(i - left), abs(right - i));
            if (i == right) // 遍历完了当前窗口后，将窗口右移
            {
                left = right;
                right++; //从right 下一个位置开始找
                while (right < S.length() && S[right] != C)
                    right++;
                
                if (right == S.length())
                    right = INT32_MAX;  //不存在right
            }
        }
        return res;
    }
};
// @lc code=end
