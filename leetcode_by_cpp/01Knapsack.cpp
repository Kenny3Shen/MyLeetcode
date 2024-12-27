#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void knapsack()
    {
        vector<int> weight = {1, 3, 4};
        vector<int> value = {15, 20, 30};
        int bagWeight = 4;
        vector<int> dp(bagWeight + 1, 0);
        for(int i = 0; i < weight.size(); i++) //tarversal things
        {
            for(int j = bagWeight; j >= weight[i]; j--) //tarversal bag weight
            {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        cout << dp[bagWeight] << endl;
        /* vector<vector<int>> dp(weight.size() + 1, vector<int>(bagWeight + 1, 0));
        for (int j = bagWeight; j >= weight[0]; j--)
            dp[0][j] = dp[0][j - weight[0]] + value[0];

        for (int i = 1; i < weight.size(); i++)
        {
            for (int j = 0; j <= bagWeight; j++)
            {
                if (j < weight[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
        cout << dp[weight.size() - 1][bagWeight] << endl; */
    }
};

int main()
{
    Solution sol;
    sol.knapsack();
    return 0;
}