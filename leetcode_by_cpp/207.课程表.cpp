/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode-cn.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (54.43%)
 * Likes:    632
 * Dislikes: 0
 * Total Accepted:    83K
 * Total Submissions: 152.5K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
 *
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
 *
 * 给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
 *
 *
 *
 * 示例 1:
 *
 * 输入: 2, [[1,0]]
 * 输出: true
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
 *
 * 示例 2:
 *
 * 输入: 2, [[1,0],[0,1]]
 * 输出: false
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
 *
 *
 *
 * 提示：
 *
 *
 * 输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。详情请参见图的表示法。
 * 你可以假定输入的先决条件中没有重复的边。
 * 1 <= numCourses <= 10^5
 *
 *
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> inDegree(numCourses);
        unordered_map<int, vector<int>> adjacent;
        int finishCourses = 0;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            inDegree[prerequisites[i][0]]++;                              //保存课程入度
            adjacent[prerequisites[i][1]].push_back(prerequisites[i][0]); //保存依赖该前置课程的课程
        }
        //BFS搜索入度为0(可以学习)的课程
        queue<int> canOut;
        for (int i = 0; i < numCourses; i++)
            if (!inDegree[i])
                canOut.push(i);
        while (!canOut.empty())
        {
            int n = canOut.size();
            for (int i = 0; i < n; i++)
            {
                int out = canOut.front();
                canOut.pop();
                finishCourses++;
                for (auto m : adjacent[out])
                    if (!(--inDegree[m]))
                        canOut.push(m);
            }
        }
        return finishCourses == numCourses;
    }
};
// @lc code=end
