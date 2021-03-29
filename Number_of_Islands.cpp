/*
200. Number of Islands
Medium

8017

241

Add to List

Share
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
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
    void printCharMat(vector<vector<char>> grid)
    {
        for(auto x: grid)
        {
            for(auto y:x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
        return;
    };

    void applyBFS(vector<vector<char>>& grid, int x, int y, int m, int n)
    {
        queue<pair<int, int>> q;
        q.push({x,y});
        grid[x][y] = '0';

        while(q.size())
        {
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;

            //now check all neighbors
            if(i+1<m && grid[i+1][j]=='1')
            {
                q.push({i+1,j});
                grid[i+1][j] = '0';
            }
            if(i-1>=0 && grid[i-1][j]=='1')
            {
                q.push({i-1,j});
                grid[i-1][j] = '0';
            }
            if(j+1<n && grid[i][j+1]=='1')
            {
                q.push({i,j+1});
                grid[i][j+1] = '0';
            }
            if(j-1>=0 && grid[i][j-1]=='1')
            {
                q.push({i,j-1});
                grid[i][j-1] = '0';
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();

        int output = 0;
        for(int i=0;i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                //if we find water continue as if nothing happened in the world
                if(grid[i][j] == '0') continue;
                applyBFS(grid, i,  j, m, n);
                output += 1;
            }
        }
        return output;
    }
};

int main()
{
   vector<vector<char>> grid = {
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'} };

    Solution sol;
    sol.printCharMat(grid);
    int output = sol.numIslands(grid);
    cout << "output is " << output << endl;
    return 0;
}