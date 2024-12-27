/*
 * @lc app=leetcode.cn id=893 lang=cpp
 *
 * [893] 特殊等价字符串组
 */
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &A)
    {
        unordered_set<string> uset;
        for (auto const &s : A)
        {
            string odd, even;
            for (int i = 0; i < s.size(); i++)
            {
                i & 1 ? even += s[i] : odd += s[i];
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            uset.insert(odd + even);
        }
        return uset.size();
    }
};
//因为可以任意次调换，所以求出偶位数的字符even，奇位数的字符odd
//同一组特殊等价字符串sort后相加相等，用set去重计数
// @lc code=end
