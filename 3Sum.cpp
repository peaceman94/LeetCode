/*
15.3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

#include<vector>
#include<iostream>
#include <cstdlib>
#include<unordered_map>
using namespace std;
class Solution {
public:
	 //does one pass 2Sum -> to be usex in 3Sum
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start){

    	vector<vector<int>> output;
    	unordered_map<int, int> ref;
    	for(int i=start; i<nums.size(); i++)
    	{
    		int comp_ele = target - nums[i];
    		if(ref.find(comp_ele) != ref.end())
    		{
    			vector<int> curr_output = {comp_ele,nums[i]};
    			output.push_back(curr_output);
    		}
    		
    		ref[nums[i]] = i;
    	}
    	return output;

    }

    //Naive: 3Sum using 2Sum
    vector<vector<int>> threeSumNaive(vector<int>& nums) {
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
        {
        	vector<vector<int>> t_s = twoSum(nums, -1*nums[i], i+1);
        	if(t_s.size())
        	{
        		for(auto it = t_s.begin(); it != t_s.end(); it++)
        		{
        			vector<int> curr_val = *it;
        			curr_val.push_back(nums[i]);
	        		if(find(output.begin(), output.end(),curr_val)==output.end())
	        		{
	        			output.push_back(curr_val);
	        		}
        		}
        	}
        }
        return output;
    }

    void printVector( vector<vector<int>> & output)
    {
    	for(int i = 0; i<output.size(); i++)
		{
			for(int j=0; j<output[i].size(); j++)
			{
				cout << output[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;	
    }
    //Thinking to see if there is an more robust method
    //Naive: 3Sum using 2Sum
    vector<vector<int>> threeSum( vector<int>& nums, int target) {

        vector<vector<int>> output;

        if(nums.size() <=2 ) return output;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-2; i++)
        {
        	if(i>0 && (nums[i-1] == nums[i]))
        	{
        		continue;
        	}

        	//cout << "i is: " << i << endl;
        	int j = i+1, k = nums.size()-1;
        	while(j<k)
        	{
        		int curr_sum = nums[i] + nums[j] + nums[k];
        		if(curr_sum == target)
        		{
        			output.push_back({nums[i], nums[j], nums[k]});
        			j++;
        			k--;

        			while(j<k && ( nums[j-1] == nums[j] ) )
        			{
        				j++;
        			}

        			while(j<k && ( nums[k] == nums[k+1] ) )
        			{
        				k--;
        			}
        		}
        		else if(curr_sum < target)
        		{
        			j++;
        		}
        		else
        		{
        			k--;
        		}

        		//printVector(output);
        	}

        }
        return output;
    }
};

int main()
{
	vector<int> nums{-1,0,1,2,-1,-4};
	//vector<int> nums{-1,0,1};

	Solution sol;
	vector<vector<int>> output = sol.threeSum(nums, 0);
	//cout << "output is: " << output << endl;

	cout << "output is: " << endl;
	sol.printVector(output);
	return 0;
}