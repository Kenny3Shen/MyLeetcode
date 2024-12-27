/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (38.42%)
 * Likes:    615
 * Dislikes: 0
 * Total Accepted:    120.3K
 * Total Submissions: 310.1K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> combinations;
    void DFS(vector<int> &nums, int begin, int sum, int target)
    {
        if (sum == target && combinations.size() == 4)
        {
            res.emplace_back(combinations);
            return;
        }
        for (int i = begin; i < nums.size(); ++i)
        {
            if (nums.size() - i < (4 - combinations.size())) //剪枝
                return;
            if (i > begin && nums[i] == nums[i - 1]) //去重
                continue;
            if (i < nums.size() - 1 && sum + nums[i] + int(3 - combinations.size()) * nums[i + 1] > target) //剪枝
                return;
            if (i < nums.size() - 1 && sum + nums[i] + int(3 - combinations.size()) * nums.back() < target) //剪枝
                continue;
            combinations.emplace_back(nums[i]);
            DFS(nums, i + 1, nums[i] + sum, target);
            combinations.pop_back();
        }
    }

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        DFS(nums, 0, 0, target);
        return res;

        /* sort(nums.begin(), nums.end());
        if (nums.size() < 4)
            return res;
        int a, b, c, d;
        for (a = 0; a <= nums.size() - 4; a++)
        {
            if (a > 0 && nums[a] == nums[a - 1])
                continue; //确保nums[a] 改变了
            for (b = a + 1; b <= nums.size() - 3; b++)
            {
                if (b > a + 1 && nums[b] == nums[b - 1])
                    continue; //确保nums[b] 改变了
                c = b + 1, d = nums.size() - 1;
                while (c < d)
                {
                    if (nums[a] + nums[b] + nums[c] + nums[d] < target)
                        c++;
                    else if (nums[a] + nums[b] + nums[c] + nums[d] > target)
                        d--;
                    else
                    {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while (c < d && nums[c + 1] == nums[c]) //确保nums[c] 改变了
                            c++;
                        while (c < d && nums[d - 1] == nums[d]) //确保nums[d] 改变了
                            d--;
                        c++;
                        d--;
                    }
                }
            }
        }
        return res; */
    }
};
// @lc code=end
