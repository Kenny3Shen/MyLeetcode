/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        vector<int> st;
        for (auto const &op : ops)
        {
            if (op == "C")
                st.pop_back();
            else if (op == "D")
                st.push_back(st.back() * 2);
            else if (op == "+")
                st.push_back(st.back() + st[st.size() - 2]);
            else
                st.push_back(stoi(op));
        }
        return accumulate(st.begin(), st.end(), 0);
    }
};
// @lc code=end
