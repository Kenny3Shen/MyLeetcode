/*
 * @lc app=leetcode.cn id=842 lang=cpp
 *
 * [842] 将数组拆分成斐波那契序列
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
    vector<int> res;

public:
    bool backtracking(string &s, int start) //find one solution should return a value
    {
        if (start == s.length() && res.size() > 2) //traversal all and have at least one Fibonacci Sequence
            return true;
        for (int i = start; i < s.length(); i++)
        {
            string piece = s.substr(start, i - start + 1);
            if (stoll(piece) > INT32_MAX)
                break; //int overflow
            if (piece.length() > to_string(stoi(piece)).length())
                break; //have extra leafing zero (zero itself should be equal)
            if (res.size() < 2 || (res.size() >= 2 && res[res.size() - 1] == stoi(piece) - res[res.size() - 2]))
            //signed integer overflow: 2 + 2147483647
            {
                res.push_back(stoi(piece));
                if (backtracking(s, i + 1))
                    return true;
                res.pop_back();
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string S)
    {
        backtracking(S, 0);
        return res;
    }
};
// @lc code=end
