/*
Baloon Burst
*/

#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), {1});
        nums.push_back(1);

        vector<vector<int> > dp(n+2, vector<int>(n+2, 0) );
        for(int l = 1; l <= n; l++){
            //cout << "l is : " << l << endl;
            for(int i = 1; i<n-l+2; i++){
                int j = i + l - 1;
                //cout << "i, j: " << i << " " << j << endl;
                for(int k = i; k<=j; k++){
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1]);
                }
            }
        }
        return dp[1][n];
    }
};     


int main(){
    
    vector<int> nums{3,1,5,8};
    Solution sol;
    int output = sol.maxCoins(nums);
    cout << "output is " << output << endl;
    return 0;
}