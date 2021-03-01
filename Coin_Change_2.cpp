/*
518. Coin Change 2

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1

*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include <numeric>
#include<string>
using namespace std;

class Solution {
public:
	unordered_map<string, int> map;
	int changeHelperTopDown(int amount, int n, vector<int>& coins)
	{
    	//Base conditions
    	if(amount == 0) return 1;
    	if(amount < 0) return 0;
    	if(amount > 0 and n <= 0 ) return 0;

		string key = to_string(amount) + '|' + to_string(n);
		if(map.find(key) != map.end()){
			return map[key];
		}

    	//output
    	int output = changeHelperTopDown(amount, n-1, coins) + changeHelperTopDown(amount - coins[n-1], n, coins);
    	map[key] = output;
    	return output;
	}

	int bottomUp(int amount, vector<int>& coins)
	{
		vector<int>dp(amount+1, 0);
		dp[0] = 1;
		for(int i = 0; i<coins.size(); i++)
		{
			for(int j=coins[i]; j<=amount; j++)
			{
				dp[j] += dp[j - coins[i]];
			}
		}
		return dp[amount];
	}
    int change(int amount, vector<int>& coins) {

    	//int output = changeHelper(amount, coins.size(), coins);
    	int output = bottomUp(amount, coins);
        return output;
    }
};

int main()
{
	vector<int> nums{1,2};
	int sum = 5;
	Solution sol;
	int output = sol.change(sum, nums);
	cout << "output is: " << output << endl;
	return 0;
}