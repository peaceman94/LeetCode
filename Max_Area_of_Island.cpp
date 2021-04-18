/*
695. Max Area of Island
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
*/

#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<set>
#include <utility>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m)
    {
    	grid[i][j] = 0;
    	int output = 1;
    	if(i+1<n && grid[i+1][j] == 1)
    	{
    		output += dfs(grid, i+1, j, n, m);
    	}
    	if(i-1>=0 && grid[i-1][j] == 1)
    	{
    		output += dfs(grid, i-1, j, n, m);
    	}
    	if(j+1<m && grid[i][j+1] == 1)
    	{
    		output += dfs(grid, i, j+1, n, m);
    	}
    	if(j-1>=0 && grid[i][j-1] == 1)
    	{
    		output += dfs(grid, i, j-1, n, m);
    	}
        return output;    
    };
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        
        int max_area = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 0) continue;
                int area = dfs(grid, i, j, n, m);
                if(area> max_area) max_area = area;
            }
        }
        return max_area;
    }
};

int main()
{
	vector<vector<int>> grid = 
	{{0,0,1,0,0,0,0,1,0,0,0,0,0},
	 {0,0,0,0,0,0,0,1,1,1,0,0,0},
	 {0,1,1,0,1,0,0,0,0,0,0,0,0},
	 {0,1,0,0,1,1,0,0,1,0,1,0,0},
	 {0,1,0,0,1,1,0,0,1,1,1,0,0},
	 {0,0,0,0,0,0,0,0,0,0,1,0,0},
	 {0,0,0,0,0,0,0,1,1,1,0,0,0},
	 {0,0,0,0,0,0,0,1,1,0,0,0,0}};

	Solution sol;
	int output = sol.maxAreaOfIsland(grid);
	cout << "output is : " << output << endl;
	return 0;
}