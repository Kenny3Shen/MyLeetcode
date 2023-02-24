/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素
 *
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (62.62%)
 * Likes:    400
 * Dislikes: 0
 * Total Accepted:    50.5K
 * Total Submissions: 80.7K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * 给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
 * 请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。
 *
 *
 *
 * 示例：
 *
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 *
 * 返回 13。
 *
 *
 *
 *
 * 提示：
 * 你可以假设 k 的值永远是有效的，1 ≤ k ≤ n^2 。
 *
 */
#include "leetcode.h"
// k路归并排序，使用最小堆维护k个指针
//  @lc code=start
class point
{
public:
    int val;
    int x;
    int y;
    point(int val, int x, int y) : val(val), x(x), y(y) {}

    bool operator>(const point &other) const // overload operator>
    {
        return this->val > other.val;
    }
};
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<point, vector<point>, greater<point>> minHeap;
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            minHeap.push(point(matrix[i][0], i, 0));
        while (k-- != 1)
        {
            point cur = minHeap.top();
            minHeap.pop();
            if (cur.y < n - 1) // cur.y == n-1时无法继续向右迭代
                minHeap.push(point(matrix[cur.x][cur.y + 1], cur.x, cur.y + 1));
        }
        return minHeap.top().val;
    }
};
// @lc code=end
