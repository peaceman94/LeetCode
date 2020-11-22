/*
416. Partition Equal Subset Sum

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include <numeric>
#include<string>
using namespace std;

class Solution {
public:

	//top down solution taking too long in leet code -> all test cases passed
	unordered_map<string, bool> map;
	bool isPossibleSumTD(vector<int> nums, int sum, int end)
	{
		string key = to_string(sum) + "_" + to_string(end);

		if(map.find(key) != map.end())
			return(map[key]);

		if(end<0 || sum<0) return false;
		if(sum == 0) return true;
		
		bool output = isPossibleSumTD(nums, sum-nums[end], end-1) || isPossibleSumTD(nums, sum, end-1);
		map[key] = output;

		cout << key << "->" << output << endl;
		return output;
	}
    bool canPartitionTD(vector<int>& nums) {
    	//if odd sum, guaranteed to be false
    	int sum = accumulate(nums.begin(), nums.end(), 0);
    	if(sum%2==1)
    		return false;
    	//sort(nums.begin(), nums.end());
    	bool output = isPossibleSumTD(nums, sum/2, nums.size()-1);
        return output;
    }

    //bottom up approach using DP Matix
	bool isPossibleSumBUDPMatrix(vector<int> nums, int sum)
	{
		vector<vector<int>> dp(nums.size() + 1, vector<int>(sum+1, false));

		//intialize sum 0 rows as true
		for(int i=0; i<nums.size()+1; i++){
			dp[i][0] = true;
		}

		for(int i=1; i<=nums.size(); i++){
			for(int j=1; j<sum +1; j++){
				//cout << "i,j is -> " << i-1 << " " << j << " ";
				if(j>=nums[i-1])
				{
					dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
					//cout << "(nums[i-1] is " << nums[i-1] << " dp is: " << dp[i][j] << " "; 
				}
				else
				{
					dp[i][j] = dp[i-1][j];
				}
				//cout << endl;
			}
		}

		return dp[nums.size()][sum];
	}

	//just DP array, instead of matrix
	bool isPossibleSumBU(vector<int> nums, int sum)
	{
		vector<int> dp(sum+1, false);
		vector<int>curr_dp(sum+1, false);

		//intialize sum 0 rows as true
		dp[0] = true;
		for(int i=1; i<=nums.size(); i++){
			for(int j=1; j<sum +1; j++){
				//cout << "i,j is -> " << i-1 << " " << j << " ";
				if(j>=nums[i-1])
				{
					curr_dp[j] = dp[j-nums[i-1]] || dp[j];
					//cout << "(nums[i-1] is " << nums[i-1] << " dp is: " << dp[i][j] << " "; 
				}
				else
				{
					curr_dp[j] = dp[j];
				}
			}

			//copy over curr_dp to update dp.
			dp = curr_dp;
		}

		return dp[sum];
	}

    bool canPartition(vector<int>& nums) {
    	//if odd sum, guaranteed to be false
    	int sum = accumulate(nums.begin(), nums.end(), 0);
    	if(sum%2==1)
    		return false;
    	bool output = isPossibleSumBU(nums, sum/2);
        return output;
    }    

};

int main()
{
	//vector<int> nums{100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97};
	//vector<int> nums{14,9,8,4,3,2};
	vector<int> nums{5,9,14, 2};
	Solution sol;
	bool output = sol.canPartition(nums);
	cout << "output is: " << output << endl;
	return 0;
}


/*
*/