/*
78. Subsets

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;


class Solution {
public:

    //still not sure why this is slow - it gets time limit exceeded for one test case (20, 16)
    void helper( vector<int>& subset, vector<int>&nums, int n, vector<vector<int>>& output)
    {
        if(n<0) return;

        //if we have the solution of size k, save to the output
        if(n==0)
        {
            output.push_back(subset);
            return;
        }

        //create subsets which have n
        subset.push_back(nums[n-1]);
        helper(subset, nums, n-1, output);
        subset.pop_back();
        
        //create subsets which dont have n
        helper(subset, nums, n-1, output);
        return;   
    };

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output = {};
        vector<int> subset = {};
        int n = nums.size();
        helper(subset, nums, n, output);
        return(output);
        
    };
};

void print_vector(vector<vector<int>> input)
{
    cout << endl << "START: printing vector of vector"<< endl;
	for(int i = 0; i<input.size(); i++)
	{
        cout << "{";
		for(int j = 0; j<input[i].size(); j++ )
		{
			cout << input[i][j] << ", ";
		}
		cout << "}"<<endl;
	}
    cout << "END: printing vector of vector"<< endl;
}; 

int main()
{
	vector<int> nums = {1,2,3};
	Solution sol;
	vector<vector<int>> output = sol.subsets(nums);
    cout << output.size() << endl;
	print_vector(output);
};