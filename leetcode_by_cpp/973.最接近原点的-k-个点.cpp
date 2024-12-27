/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 *
 * https://leetcode-cn.com/problems/k-closest-points-to-origin/description/
 *
 * algorithms
 * Medium (58.83%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    48K
 * Total Submissions: 76.2K
 * Testcase Example:  '[[1,3],[-2,2]]\n1'
 *
 * 我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。
 * 
 * （这里，平面上两点之间的距离是欧几里德距离。）
 * 
 * 你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：points = [[1,3],[-2,2]], K = 1
 * 输出：[[-2,2]]
 * 解释： 
 * (1, 3) 和原点之间的距离为 sqrt(10)，
 * (-2, 2) 和原点之间的距离为 sqrt(8)，
 * 由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
 * 我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
 * 
 * 
 * 示例 2：
 * 
 * 输入：points = [[3,3],[5,-1],[-2,4]], K = 2
 * 输出：[[3,3],[-2,4]]
 * （答案 [[-2,4],[3,3]] 也会被接受。）
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= K <= points.length <= 10000
 * -10000 < points[i][0] < 10000
 * -10000 < points[i][1] < 10000
 * 
 * 
 */
#include <queue>
#include <vector>
#include <functional>
using namespace std;
// @lc code=start
class Solution
{
    // 大顶堆比较函数
    class my_comparison
    {
    public:
        bool operator()(const pair<int, vector<int>> &lhs, const pair<int, vector<int>> &rhs)
        {
            return lhs.first < rhs.first;
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        /* sort(points.begin(),points.end(),[&](vector<int> a,vector<int>b){
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        });
        points.resize(K);   //取前K个数
        return points; */

        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, my_comparison> pri_que;
        //             Type                    Container               functional(default max-heap)
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            pair<int, vector<int>> p(x * x + y * y, points[i]);
                                //key=EuclidDistance  value=(x,y)
            pri_que.push(p);
            if(pri_que.size() > K)
                pri_que.pop(); //堆顶最大的元素出堆
        }

        vector<vector<int>> result(K); // 把队列里元素放入数组
        for (int i = 0; i < K; i++) {
            result[i] = pri_que.top().second;
            pri_que.pop();
        }
        return result;
    }
};
// @lc code=end
