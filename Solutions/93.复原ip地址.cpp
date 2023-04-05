/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (49.08%)
 * Likes:    391
 * Dislikes: 0
 * Total Accepted:    74.7K
 * Total Submissions: 152.1K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 * 
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是
 * "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "1111"
 * 输出：["1.1.1.1"]
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "010010"
 * 输出：["0.10.0.10","0.100.1.0"]
 * 
 * 
 * 示例 5：
 * 
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 3000
 * s 仅由数字组成
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> result;
    void DFS_search(string s, int n, string ipAddresses)
    {
        if (n > 4) // n > 4
            return;
        if (n == 4 && s.empty()) // n = 4
        {
            ipAddresses.pop_back(); //remove the last character '.'
            result.push_back(ipAddresses);
            return;
        }
        //长度小于剩下段的最小长度  长度超过剩下段最大长度
        if (s.size() < 4 - n || s.size() > (3 * (4 - n))) // 0 < n < 4
            return;
        else
        {
            for (int i = 1; i < 4; i++) //每个ip段最多分3位
            {
                if (s.size() < i) //剩余长度无法分配
                    return;
                string ipAddPart = s.substr(0, i);
                int ipNum = stoi(ipAddPart);
                if (ipNum > 255 || ipAddPart.size() != to_string(ipNum).size())
                    return; //ip段值不符合条件 or ip段包含前导的 0
                DFS_search(s.substr(i), n + 1, ipAddresses + ipAddPart + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        DFS_search(s, 0, "");
        return result;
    }
};
// @lc code=end
