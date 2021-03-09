/*
77. Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
1 <= k <= n
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
    void helper( vector<int> subset, int n, vector<vector<int>>& output, int k)
    {
        if(n<0) return;

        //if we have the solution of size k, save to the output
        if(subset.size() == k)
        {
            output.push_back(subset);
            return;
        }
        //create subsets which have n
        vector<int> curr_subset = subset;
        curr_subset.push_back(n);
        helper(curr_subset, n-1, output, k);

        //create subsets which dont have n
        helper(subset, n-1, output, k);
        return;   
    };

    void helper_fast(vector<int> sub, int n, int k, int start, int size, vector<vector<int>>& output)
    {
        if(size == k)
        {
            output.push_back(sub);
        }

        for(int i=start; i<n; i++)
        {   
            sub.push_back(i+1);
            helper_fast(sub, n, k, i+1, size+1, output);
            sub.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> output = {};
        vector<int> subset = {};
        //helper(subset, n, output, k);
        helper_fast(subset, n, k, 0, 0, output);
        return(output);
    }
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
	int n = 20, k = 16;
	Solution sol;
	vector<vector<int>> output = sol.combine(n, k);
    cout << output.size() << endl;
	//print_vector(output);
};