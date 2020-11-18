/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/
#include<iostream>
#include<vector>
#include<cmath>
#include <stdint.h>
#include <limits.h>
#include<unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<int,int> map;
    int coinChangetopDown(vector<int>& coins, int amount) {

        if(map.find(amount) != map.end())
            return(map[amount]);

        //if amount is zero return 0
        if(amount == 0) return 0;
        int min = INT_MAX;
        for(int i=0; i< coins.size(); i++){
            int net_amt = amount - coins[i];
            if(net_amt < 0) continue;
            int curr = coinChange(coins, net_amt);
            if(curr != -1 && (curr+1<min) ) min = curr+1;
        }
        map[amount] = (min == INT_MAX) ? -1: min;
        return map[amount];
    }

    int coinChange(vector<int>& coins, int amount){
        vector<int> dp(amount+1, 0);
        for(int i=1; i<=amount; i++){
            dp[i] = INT_MAX;
            for(int j=0; j< coins.size(); j++){
                if((i-coins[j]) >= 0 && dp[i-coins[j]] != -1)
                {
                     dp[i] = min(dp[i], 1+ dp[i-coins[j]] );
                }
            }
            dp[i] = (dp[i] == INT_MAX) ? -1: dp[i];
            cout << "i is: " << i << " DP is " << dp[i] << endl;
        }        
        return dp[amount];
    }
};

int main(){
    //vector<int> coins{2};
    vector<int> coins{2,5, 10, 1};
    int amount = 27;
    Solution sol;
    int output = sol.coinChange(coins, amount);
    cout << "output is: " << output << endl;
    return 0;
}
  
