/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
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
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        vector<string> res;
        unordered_map<string, int> map;
        for (string const &word : cpdomains)
        {
            int index = word.find(' ');
            int accessCount = stoi(word.substr(0, index)); //找到访问次数
            string domainName = word.substr(index + 1);    //取访问域名

            while (index != string::npos)
            {
                map[domainName] += accessCount;            //统计域名访问次数
                index = domainName.find('.');              //取上级域名
                domainName = domainName.substr(index + 1); //取上级域名
            }
        }
        for (auto const &m : map)
            res.push_back(to_string(m.second) + ' ' + m.first);
        return res;
    }
};
// @lc code=end
