class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, int m, int n, unordered_map<string, int> &map)
    {
        string key = to_string(i) + "_" + to_string(j);
        if(map.find(key) != map.end()) return map[key];
        int output;
        
        if(i >= m || j>= n) output = INT_MAX;
        else if(i == m-1 && j == n-1)
        {
            output = grid[m-1][n-1];
        }
        else
        {
            output = min(helper(grid, i+1, j, m, n, map), helper(grid, i, j+1, m, n, map)) + grid[i][j];
        }
         map[key] = output;
         return output;
    }
    
    int minPathSumTD(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        
        unordered_map<string, int> map;
        int output = helper(grid, 0, 0, m, n, map);
        return output;
    }
};
