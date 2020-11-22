/*

368. Largest Divisible Subset

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	int n = nums.size();
    	if(n==0)
    	{
    		vector<int> output;
    		return output;
    	}
       	
       	vector<int> dp(n,1);
       	vector<int> ind_x(n, -1);
       	sort(nums.begin(), nums.end());
       	for(int i = 0; i< nums.size(); i++){
       		for(int j = 0; j<i; j++)
       		{
       			if( (nums[i] % nums[j]) == 0)
       			{
       				if(dp[i] < (dp[j]+1))
       				{
       					dp[i] = dp[j]+1;
       					ind_x[i] = j;
       				}
       			}
       		}
       	}

       	int max_ind = distance(dp.begin(), max_element(dp.begin(), dp.end()));
       	int max = dp[max_ind];

       	//start printing the solution
       	vector<int> output;
       	while(max)
       	{
       		output.push_back(nums[max_ind]);
       		max_ind  = ind_x[max_ind];
       		max--;
       	}
        return output;
    }
};

int main(){
	//intput
	vector<int> nums{1,2,3,4,8};

	Solution sol;
	//int output = sol.largestDivisibleSubset(nums);
	//cout << "output is: " << output << endl;
	vector<int> output = sol.largestDivisibleSubset(nums);
	//print the output
	
	for(int i=0; i< output.size(); i++){
		cout << output[i] << " ";
	}
	cout << endl;
	//return 
	return 0;
}