/* 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5 */
#include <vector>
using namespace std;
class Solution
{
public:
    //双指针滑动窗口, 
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> res;
        int i = 1, j = 1;
        int sum = 0;
        while (i <= (target - 1) / 2) //i、j依次为窗口的左右端点，sum为窗口内序列的和，i的上界和上面一样
        {
            if (sum < target) //两个指针均单调不减，小于target那么右端点右移，加入新的元素
            {
                sum += j;
                j++;
            }
            else if (sum > target) //大于target，那么就左端点右移，去掉元素i
            {
                sum -= i;   //target - sum 缺的部分通过减去前面最小的元素补上
                i++;
            }
            else
            {
                vector<int> tmp;
                for (int k = i; k < j; k++)
                {
                    tmp.push_back(k);
                }
                res.push_back(tmp);
                sum -= i; //i开头的满足条件的序列找到了，那么i右移，继续找i+1开头的序列
                i++;
            }
        }
        return res;
    }
};

/* class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int begin = (target / 2) + 1;
        vector<int> combination;
        DFS(begin,target,combination);
        reverse(res.begin(),res.end());
        return res;
    }

    void DFS(int begin, int target, vector<int> & combination)
    {
        if(target < 0)
            return;
        if(target == 0)
        {
            reverse(combination.begin(),combination.end());
            res.push_back(combination);
            return;
        }

        for(int i = begin; i > 0; i--)
        {
            if(!combination.empty())
                if(combination.back() - i > 1 || combination.back() - i <= 0)
                    return;
            if(target - i < 0)
                return;
            else
            {
                combination.push_back(i);
                DFS(i - 1, target - i, combination);
                combination.pop_back();
            }
        }
    }
private:
    vector<vector<int>> res;
}; */