/*
 * @lc app=leetcode.cn id=2032 lang=cpp
 *
 * [2032] 至少在两个数组中出现的值
 *
 * https://leetcode.cn/problems/two-out-of-three/description/
 *
 * algorithms
 * Easy (66.40%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    20.1K
 * Total Submissions: 28K
 * Testcase Example:  '[1,1,3,2]\n[2,3]\n[3]'
 *
 * 给你三个整数数组 nums1、nums2 和 nums3 ，请你构造并返回一个 元素各不相同的 数组，且由 至少 在 两个
 * 数组中出现的所有值组成。数组中的元素可以按 任意 顺序排列。
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
 * 输出：[3,2]
 * 解释：至少在两个数组中出现的所有值为：
 * - 3 ，在全部三个数组中都出现过。
 * - 2 ，在数组 nums1 和 nums2 中出现过。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
 * 输出：[2,3,1]
 * 解释：至少在两个数组中出现的所有值为：
 * - 2 ，在数组 nums2 和 nums3 中出现过。
 * - 3 ，在数组 nums1 和 nums2 中出现过。
 * - 1 ，在数组 nums1 和 nums3 中出现过。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
 * 输出：[]
 * 解释：不存在至少在两个数组中出现的值。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums1.length, nums2.length, nums3.length <= 100
 * 1 <= nums1[i], nums2[j], nums3[k] <= 100
 *
 *
 */
#include "leetcode.h"
#include <vector>
#include <unordered_set>
// @lc code=start
class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        unordered_map<int, int> a, b, c;
        unordered_set<int> res;
        for (auto t : nums1)
            a[t]++;
        for (auto t : nums2)
            b[t]++;
        for (auto t : nums3)
            c[t]++;
        for (auto m : a)
            if (b.count(m.first) || c.count(m.first))
                res.insert(m.first);
        for (auto m : b)
            if (a.count(m.first) || c.count(m.first))
                res.insert(m.first);
        for (auto m : c)
            if (b.count(m.first) || a.count(m.first))
                res.insert(m.first);
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end
