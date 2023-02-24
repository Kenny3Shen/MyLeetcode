/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> numsCntMap;    //numsCntMap[num]表示的是num剩余的个数
        unordered_map<int, int> numsEndCntMap; //numsEndCntMap[num]表示的时以num结尾的连续子序列（长度不小于3）个数
        //统计各个元素出现的次数
        for (auto num : nums)
        {
            numsCntMap[num] += 1;
        }
        //开始访问各个元素
        for (auto num : nums)
        {
            if (numsCntMap[num] == 0)
            { //此元素没有剩余，已经被使用完了
                continue;
            }
            numsCntMap[num] -= 1; //剩余个数自减
            if (numsEndCntMap.count(num - 1) && numsEndCntMap[num - 1] > 0)
            {
                //存在以num - 1结尾的连续子序列（长度不小于3），则将num放入
                numsEndCntMap[num - 1] -= 1; //以num - 1结尾的连续子序列（长度不小于3）自减，因为被num放入使用了一个
                numsEndCntMap[num] += 1;     //以num结尾的连续子序列（长度不小于3）自增，刚刚创建了一个
            }
            else if (numsCntMap.count(num + 1) && numsCntMap[num + 1] && numsCntMap.count(num + 2) && numsCntMap[num + 2])
            {
                //否则查找后面两个元素，凑出一个合法的序列
                numsCntMap[num + 1] -= 1;
                numsCntMap[num + 2] -= 1;
                numsEndCntMap[num + 2] += 1;
            }
            else
            {
                //两种方法都不行，则凑不出，比如[1,2,3,4,4,5]中的第二个4，
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
