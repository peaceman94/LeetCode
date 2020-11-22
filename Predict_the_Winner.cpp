/*
486. Predict the Winner

Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:

Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.
 

Example 2:

Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
 

Constraints:

1 <= length of the array <= 20.
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include <numeric>
#include<string>
using namespace std;


//Note: see leetcode solution: its different and better! (min-Max Algorithm)
class Solution {
public:
	bool helper( vector<int>& nums )
	{
		int n = nums.size();
		if(n==1) return true;
		if(n==2)
		{
			return true;
		}

		vector<vector<int>> dp(nums.size()+2, vector<int>(nums.size()+2, 0));
		for(int i=0; i<nums.size(); i++){
			dp[i][i+2] = nums[i];
			if(i != nums.size()-1)
			{
				dp[i][i+3] = max(nums[i], nums[i+1]);
			}
		}

		for(int i = n-1; i>=0; i--)
		{
			for(int j= i+4; j<nums.size()+2; j++)
			{
				//cout << "i and j is: " << i << " " << j << endl;
				dp[i][j] = max(
									( nums[i] + min( dp[i+2][j], dp[i+1][j-1]) ), 
									( nums[j-2] + min( dp[i][j-2], dp[i+1][j-1])  )
							  );
			}
		}

		//print
		/*
		for(int i=0; i<nums.size()+2; i++){
			for(int j=0; j<nums.size()+2; j++){
				cout << dp[i][j] << "\t";
			} 
			cout << endl;
		} 
		cout << endl;
		*/

		bool output = dp[0][n+1] >= min(dp[1][n+1], dp[0][n]);
		return output;
	}

    bool PredictTheWinner(vector<int>& nums) {
    	bool output = helper(nums);
        return output;
    }
};

int main()
{
	//vector<int> nums{1,5,233,7};
	vector<int> nums{1,5,2,4,6};
	Solution sol;
	bool output = sol.PredictTheWinner(nums);
	cout << "output is: " << output << endl;
	return 0;
}

