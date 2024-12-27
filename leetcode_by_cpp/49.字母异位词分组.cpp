/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
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
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for (auto const &s : strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            map[temp].push_back(s);
        }
        for (auto &m : map)
            res.push_back(move(m.second)); //m.second不再使用，move节省内存
        return res;

        /* vector<vector<string>> res;
        unordered_map <double,vector<string> > m;
        int a[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        for(string& s : strs)
        {
            double t = 1;
            for(char c : s)
                t *= a[c - 'a'];
            m[t].push_back(s);          //t为单词对应的质数乘积，m[t]则为该单词的异位词构成的vector
        }
        for(auto& n : m)                //n为键和值组成的pair
            res.push_back(n.second);
        return res; */
    }
};
// @lc code=end
