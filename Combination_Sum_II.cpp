/*
40. Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
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
	void helper(vector<int>& candidates, int target, vector<int> curr_sol, int curr_index)
	{

		if(target == 0)
		{
			output.push_back(curr_sol);
			return;
		};

		//return if we arent able to find :(
		if(curr_index == candidates.size())
			return;

		//for each print the potential solution
		for(int i=curr_index; i<candidates.size(); i++)
		{
			//find howmany elements are there which are same
			int curr_ele = candidates[i];
			int count = 0;
			while(i<candidates.size() && candidates[i] == curr_ele)
			{
				count++;
				i++;
			};
			i--;  //i already increases in the for loo counter in the end

			//now we can try if we are able to accive the sum using 1,...count number of curr_ele			
			for(int j=1; j<=count; j++)
			{
				int next_target = target - j * curr_ele;
				//if the curr_element is greater than the target continue;
				if(next_target < 0) continue;

				vector<int> next_curr_sol = curr_sol;
				int t = j;
				while(t)
				{
					next_curr_sol.push_back(curr_ele);
					t--;
				}
				helper(candidates, next_target, next_curr_sol, i+1);
			}	
		}
		return;
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr_sol = {};
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, curr_sol, 0);
        return output;
    }

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
};



int main()
{
	vector<int> candidates = {10,1,2,7,6,1,5};
	int target = 8;

	//vector<int> candidates = {1,1,1,2};
	//int target = 3;

	Solution sol;
	vector<vector<int>> output = sol.combinationSum2(candidates, target);
	sol.print_vector(output);
};

