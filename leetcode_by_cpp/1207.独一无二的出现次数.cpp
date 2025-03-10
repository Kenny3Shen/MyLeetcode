/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 *
 * https://leetcode-cn.com/problems/unique-number-of-occurrences/description/
 *
 * algorithms
 * Easy (69.33%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 20.2K
 * Testcase Example:  '[1,2,2,1,1,3]'
 *
 * 给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
 * 
 * 如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [1,2,2,1,1,3]
 * 输出：true
 * 解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,2]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 1000
 * -1000 <= arr[i] <= 1000
 * 
 * 
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        /* unordered_map<int, int> map; //计数
        unordered_set<int> set;      //去重
        for (auto i : arr)
            map[i]++;
        for (auto m : map)
            set.insert(m.second);
        return map.size() == set.size(); */

        int count[2002] = {0}; // 统计数字出现的频率
        for (int i = 0; i < arr.size(); i++)
        {
            count[arr[i] + 1000]++; //-1000 <= arr[i] <= 1000
        }
        bool fre[1002] = {false}; // 看相同频率是否重复出现
        for (int i = 0; i <= 2000; i++)
        {
            if (count[i])
            {
                if (fre[count[i]] == false)
                    fre[count[i]] = true;
                else //出现过相同出现次数的数
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
