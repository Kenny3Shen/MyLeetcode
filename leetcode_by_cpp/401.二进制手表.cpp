// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 *
 * https://leetcode-cn.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (52.31%)
 * Likes:    157
 * Dislikes: 0
 * Total Accepted:    17.2K
 * Total Submissions: 33K
 * Testcase Example:  '0'
 *
 * 二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。
 * 
 * 每个 LED 代表一个 0 或 1，最低位在右侧。
 * 
 * 
 * 
 * 例如，上面的二进制手表读取 “3:25”。
 * 
 * 给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: n = 1
 * 返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16",
 * "0:32"]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输出的顺序没有要求。
 * 小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
 * 分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。
 * 超过表示范围（小时 0-11，分钟 0-59）的数据将会被舍弃，也就是说不会出现 "13:00", "0:61" 等时间。
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int hammingWeight(int i)
    {
        int w = 0;
        while (i)
        {
            i = i & (i - 1);
            w++;
        }
        return w;
    }
    vector<string> readBinaryWatch(int num)
    {
        vector<string> res;
        for (int h = 0; h < 12; h++)
            for (int m = 0; m < 60; m++)
                if (hammingWeight(h) + hammingWeight(m) == num)
                    res.push_back(to_string(h) + ":" + (m < 10 ? "0" + to_string(m) : to_string(m)));
        return res;
    }
};
// @lc code=end
