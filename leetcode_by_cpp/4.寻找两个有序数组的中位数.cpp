/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (37.14%)
 * Likes:    2346
 * Dislikes: 0
 * Total Accepted:    163.8K
 * Total Submissions: 440.6K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        int n1,n2;
        if(nums1.size() % 2 == 0 )
            n1= nums1[nums1.size()/2];
        else
        {
            vec.push_back(nums1.size()/2);
            vec.push_back(nums1.size()/2 + 1);
        }
        if(nums2.size() % 2 == 0)
           n2= nums2[nums2.size()/2];
        else
        {
            vec.push_back(nums2.size()/2);
            vec.push_back(nums2.size()/2 + 1);
            sort(vec.begin(),vec.end());
            n1 = vec[1];
            n2=vec[2];
        }
        return (double)(n1+n2)/2;

    }
};
// @lc code=end

