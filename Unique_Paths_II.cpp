/*
63. Unique Paths II

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/
#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<set>
#include <numeric>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    void printIntVect(vector<vector<int>>& obstacleGrid)
    {
        for(auto x: obstacleGrid)
        {
            for(int y:x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
    };
    int helper(vector<vector<int>>& obstacleGrid, int i, int j, int m, int n, unordered_map<string, int> &map)
    {
        int output = 0;

        //first check the cache
        string key = to_string(i) + "_" + to_string(j);
        if(map.find(key) != map.end())
        {
            return map[key];
        };

        //set boundary conditions
        if( (i==m-2 && j==n-1 ) || (j ==n-2 && i == m-1) )
        {
            
            output = 1;
            map[key] = output;
            return output;
        };
        
        if(i+1<m && obstacleGrid[i+1][j] == 0)
        {
            output = output + helper(obstacleGrid,i+1,j, m, n, map);
        };

        if(j+1<n && obstacleGrid[i][j+1] == 0)
        {
            output = output + helper(obstacleGrid,i,j+1, m, n, map);
        };

        map[key] = output;
        return output;
    };

    int uniquePathsWithObstaclesTopDown(vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        if(m==0) return 0;
        int n = obstacleGrid[0].size();

        //impossible or totally possible conditions
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        if(m == 1 && n == 1 && obstacleGrid[m-1][n-1] == 0) return 1;

        unordered_map<string, int> map;
        int output = helper(obstacleGrid,0,0, m, n, map);
        return output;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        if(m==0) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = m-1; i>=0; i--)
        {
            for(int j = n-1;j>=0; j--)
            {
                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j] == 0;
                    continue;
                }

                if(i == m-1 && j == n-1)
                {
                    dp[i][j] = 1;
                    continue;
                }
                if(i==m-1){dp[i][j] = dp[i][j+1];}
                else if(j==n-1){dp[i][j] = dp[i+1][j];}
                else {dp[i][j] = dp[i][j+1] + dp[i+1][j];};
            }
        }
        return dp[0][0];
    }    
};

int main()
{
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    Solution sol;
    sol.printIntVect(obstacleGrid);
    int output = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << "Output is " << output << endl;
    return 0;
}