/*
47. Permutations II
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/
#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, int start, vector<vector<int>>& output)
	{
        //cout << start << endl;
		if(start==nums.size())
		{
            //cout << "yay" << endl;
			output.push_back(nums);
			return;
		}

        set<int, greater<int> > lucky_bastards;
		for(int i=start; i<nums.size(); i++)
		{
            //whoever has got the front row ticket shall not get it again
            if(lucky_bastards.find(nums[i]) == lucky_bastards.end())
            {
                lucky_bastards.insert(nums[i]);
            }
            else
            {
                continue;
            };

            swap(nums[i], nums[start]);
			helper(nums, start+1, output);
			swap(nums[i], nums[start]);
		}
	}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output ={};
        helper(nums, 0, output);
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
	vector<int> candidates = {1, 1, 2, 2};
	Solution sol;
	vector<vector<int>> output = sol.permuteUnique(candidates);
	print_vector(output);
};