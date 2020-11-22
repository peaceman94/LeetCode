/*
377. Combination Sum IV

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
 

Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	unordered_map<int, int> map;

	//have very little idea as to why this works lol but it does
    int combinationSum4Khandes(vector<int>& nums, int target) {
    	
    	if(map.find(target) != map.end())
    		return(map[target]);

    	//base cases
    	if(target == 0 ) return 0;
    	
    	int output = 0;
    	for(int i=0; i< nums.size(); i++){
    		//assume the nums[i] is included in the target.
    		if(nums[i] < target)
    			output += combinationSum4Khandes(nums, target - nums[i]);
    		if(nums[i] == target) output +=1;
    	}
    	map[target] = output;
    	return output;
    }

    int combinationSum4(vector<int>& nums, int target)
    {
    	vector<unsigned int> dp(target + 1);
    	dp[0] = 1;
    	for( int i =0; i<= target; i++){
    		for( int j = 0; j<nums.size(); j++)
    		{
    			if(nums[j]<=i)
    				dp[i] += dp[i - nums[j]];
    		}
    	}
    	return dp[target];
    }
};

int main()
{
	vector<int> nums{1,2,3};
	int t = 4;

	Solution sol;
	//int output = sol.combinationSum4Khandes(nums, t);
	int output = sol.combinationSum4(nums, t);
	cout << "output is: " << output << endl;
	return 0;
}