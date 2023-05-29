/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
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
    vector<string> uncommonFromSentences(string A, string B)
    {
        vector<string> res;
        stringstream ss(A + ' ' + B);
        string word;
        unordered_map<string, int> map;
        while (ss >> word)
            map[word]++;
        for (auto &m : map)
            if (m.second == 1)
                res.push_back(m.first);

        return res;
    }
};
// @lc code=end
