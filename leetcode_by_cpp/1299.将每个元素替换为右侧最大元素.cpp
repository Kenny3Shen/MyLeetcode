/*
 * @lc app=leetcode.cn id=1299 lang=cpp
 *
 * [1299] 将每个元素替换为右侧最大元素
 *
 * https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side/description/
 *
 * algorithms
 * Easy (77.39%)
 * Likes:    39
 * Dislikes: 0
 * Total Accepted:    16.6K
 * Total Submissions: 21.5K
 * Testcase Example:  '[17,18,5,4,6,1]'
 *
 * 给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。
 * 
 * 完成所有替换操作后，请你返回这个数组。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：arr = [17,18,5,4,6,1]
 * 输出：[18,6,6,6,1,-1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 1 <= arr[i] <= 10^5
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--)
        {
            int temp = arr[i];
            arr[i] = max;
            if(temp > max)
                max = temp;
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
};
// @lc code=end

