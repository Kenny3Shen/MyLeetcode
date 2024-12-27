/*
 * @lc app=leetcode.cn id=1642 lang=cpp
 *
 * [1642] 可以到达的最远建筑
 */
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        // 由于我们需要维护最大的 l 个值，因此使用小根堆
        priority_queue<int, vector<int>, greater<int>> pri;
        for (int i = 1; i < heights.size(); i++)
        {
            int heightDiff = heights[i] - heights[i - 1];
            if (heightDiff > 0)
            {
                pri.push(heightDiff);

                // 如果优先队列已满，需要拿出一个其中的最小值，改为使用砖块
                if (pri.size() > ladders)
                {
                    bricks -= pri.top(); //最小值出堆,使用砖头,剩下堆中的较大值使用梯子
                    pri.pop();
                }
                if (bricks < 0) //砖头用完了，说明这一层 i是无法到达的，应该 -1
                    return i - 1;
            }
        }
        return heights.size() - 1;
    }
};
// @lc code=end
