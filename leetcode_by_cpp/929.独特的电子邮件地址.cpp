/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> set;
        for (auto &email : emails)
        {
            int index = 0;
            while (email[index] != '@')
                index++;
            string localName = email.substr(0, index); //@之前的
            string domainName = email.substr(index);   //@之后的
            string realLocalName = "";
            for (auto const &c : localName)
            {
                if (c == '.')
                    continue;
                else if (c == '+')
                    break;
                else
                    realLocalName.push_back(c);
            }
            set.insert(realLocalName + domainName);
        }
        return set.size();
    }
};
// @lc code=end
