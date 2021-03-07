/*
46. Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/

#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

class Solution {
public:
	vector<vector<int>> output;

	void print_single_vector(vector<int> input)
	{
		for(int i=0; i< input.size(); i++)
		{
			cout << input[i] << " ";
		};
		cout << endl;
	}
	void helper_non_optimized(vector<int>& nums, vector<int> curr_perm)
	{
		if(nums.size() == 0) return;
		if(nums.size() == 1)
		{
			curr_perm.push_back(nums[0]);
			output.push_back(curr_perm);
		}

		for(int i=0; i<nums.size(); i++)
		{
			vector<int> next_curr_perm = curr_perm;
			next_curr_perm.push_back(nums[i]);
			
			auto start = nums.begin();
			auto mid = nums.begin() + i ;
			auto end = nums.end();
			vector<int> next_nums_1(start, mid);
			vector<int> next_nums_2(mid +1, end);

			next_nums_1.insert(next_nums_1.end(), next_nums_2.begin(), next_nums_2.end());
			helper_non_optimized(next_nums_1, next_curr_perm);

		}
		return;
	};

	void helper(vector<int>& nums, int start)
	{
		if(start==nums.size())
		{
			output.push_back(nums);
			return;
		}

		for(int i=start; i<nums.size(); i++)
		{
			swap(nums[i], nums[start]);
			helper(nums, start+1);
			swap(nums[i], nums[start]);
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr_perm = {};
        //helper_non_optimized(nums, curr_perm);
        helper(nums, 0);
        return output;
    }
};

void print_vector(vector<vector<int>> input)
{
	for(int i = 0; i<input.size(); i++)
	{
		for(int j = 0; j<input[i].size(); j++ )
		{
			cout << input[i][j] << " ";
		}
		cout << endl;
	}
}; 

int main()
{
	vector<int> candidates = {1,2, 3};
	Solution sol;
	vector<vector<int>> output = sol.permute(candidates);
	print_vector(output);
};