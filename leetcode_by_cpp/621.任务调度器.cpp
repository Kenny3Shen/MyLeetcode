/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int len = tasks.size();
        vector<int> vec(26);
        for (char c : tasks)
            vec[c - 'A']++;
        sort(vec.rbegin(), vec.rend()); //vec[0]是单个种类任务数的最大值

        int lastBucketTasks = 1; //最后一个桶的任务数，从 1开始，因为至少有一个vec[0]
        //单个种类任务数的最大值不止一个，则 lastBucketTasks++
        while (lastBucketTasks < vec.size() && vec[lastBucketTasks] == vec[0])
            lastBucketTasks++;
        return max(len, lastBucketTasks + (n + 1) * (vec[0] - 1));
        //存在空闲时间(待命)肯定是lastBucketTasks + (n + 1) * (vec[0] - 1)大
        //不存在空闲时间(待命)肯定是 tasks.size() >= 存在空闲时间
    }
};
// @lc code=end
