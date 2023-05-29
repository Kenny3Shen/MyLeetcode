/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 *
 * [1720] 解码异或后的数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        vector<int> arr(encoded.size() + 1);
        arr[0] = first;              //arr[0]
        arr[1] = encoded[0] ^ first; //arr[1]
        for (int i = 1; i < encoded.size(); i++) //arr[2] ~ arr[i]
        {
            arr[i + 1] = encoded[i] ^ arr[i];
        }
        return arr;
    }
};
//encoded[i] = arr[i] XOR arr[i + 1]

//encoded[0] = arr[0](first) XOR arr[1]
//encoded[1] = arr[1] XOR arr[2]
//arr[1] = encoded[0] ^ first
//arr[2] = encoded[1] ^ arr[1]
//arr[i] = encoded[i - 1] ^ arr[i - 1]
// @lc code=end
