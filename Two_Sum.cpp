/*
1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

*/
#include<vector>
#include<iostream>
#include <cstdlib>
#include<unordered_map>
using namespace std;

class Solution {
public:
	//does 2 passes of the map
    vector<int> twoSumHashMap(vector<int>& nums, int target) {
    	
    	//output
    	vector<int> output;

    	//store the index of each element
    	unordered_map<int, vector<int>> ref;
    	for(int i=0; i< nums.size(); i++)
    	{
    		ref[nums[i]].push_back(i);
    	}

    	for(auto i = ref.begin(); i!= ref.end(); i++)
    	{
    		int ele = i->first;
    		int comp_ele = target - ele;

    		if(ref.find(comp_ele) == ref.end()) continue;

    		int ind = ref[ele].back();
    		ref[ele].pop_back();
    		
    		if(ref[comp_ele].size())
    		{
    			int comp_ind = ref[comp_ele].back();
    			ref[comp_ele].pop_back();
    			output.push_back(comp_ind);
    			output.push_back(ind);
    			break;
    		}
    	}
        return  output;
    }

    //does one pass
    vector<int> twoSum(vector<int>& nums, int target){

    	vector<int> output;
    	unordered_map<int, int> ref;
    	for(int i=0; i<nums.size(); i++)
    	{
    		int comp_ele = target - nums[i];
    		if(ref.find(comp_ele) != ref.end())
    		{
    			output = {ref[comp_ele],i};
    			return output;
    		}
    		
    		ref[nums[i]] = i;
    	}
    	return output;

    }
};

int main()
{
	vector<int> nums{3,3};
	//vector<int> nums{3,2,4};
	int target = 6;

	Solution sol;
	//vector<int> output = sol.twoSumHashMap(nums, target);
	vector<int> output = sol.twoSum(nums, target);
	cout << "output is: ";
	for(int i = 0; i<output.size(); i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
	return 0;
}