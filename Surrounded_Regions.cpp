/*
130. Surrounded Regions

Given an m x n matrix board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.


Example 1:
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/

#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<iostream>
#include <set>

using namespace std;

class Solution {
public:
	void helper(vector<vector<char>>& board, int x, int y)
	{
		//cout << "Working on: " << x << " " << y << endl;
		int m = board.size();
		if(m == 0) return;
		int n = board[0].size();

		//check if the input x and y are from America (Freedom)
		if(x==m-1 || y==n-1 || x == 0 || y == 0) return;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		queue<pair<int, int>> q;
		
		//push current state in queue and mark it as visited
		bool hit_boundary = false;
		q.push({x,y});
		visited[x][y] = true;

		while(q.size())
		{
			auto curr_cood = q.front();
			int i = curr_cood.first;
			int j = curr_cood.second;
			q.pop();

			if(i+1<m && board[i+1][j] == 'O' && !visited[i+1][j])
			{
				q.push({i+1, j});
				visited[i+1][j] = true;
				if(i+1 == m-1) hit_boundary = true;
			}

			if(i-1>=0 && board[i-1][j] == 'O'  && !visited[i-1][j] )
			{
				q.push({i-1, j});
				visited[i-1][j] = true;
				if(i-1 == 0) hit_boundary = true;
			}

			if(j-1>=0 && board[i][j-1] == 'O'  && !visited[i][j-1])
			{
				q.push({i, j-1});
				visited[i][j-1] = true;
				if(j-1 == 0) hit_boundary = true;
			}

			if(j+1<n && board[i][j+1] == 'O' && !visited[i][j+1] )
			{
				q.push({i, j+1});
				visited[i][j+1] = true;
				if(j+1 == n-1) hit_boundary = true;
			}
		}

		//if boundary is hit -> this means that the block of 'O's cannot be captured
		if(!hit_boundary)
		{
	    	for(int i = 0; i<m; i++)
	    	{
	    		for(int j=0; j<n; j++)
	    		{
	    			if(visited[i][j])
	    			{
	    				//cout << i <<  " " << j << endl;
	    				board[i][j] = 'X';
	    			}
	    		}
	    	}

		}		
	}

    void solve(vector<vector<char>>& board) {
    	for(int i = 0; i<board.size(); i++)
    	{
    		for(int j=0; j<board[0].size(); j++)
    		{
    			if(board[i][j] == 'X') continue;
    			helper(board, i, j);
    		}
    	}
        return;
    }
};

void printV(vector<vector<char>>& board)
{
		//print board
	for(auto x: board)
	{
		for(auto y: x)
		{
			cout << y << " ";
		}
		cout << endl;
	}

}
int main()
{
	//vector<vector<char>> board = {{'X','X', 'X', 'X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
	vector<vector<char>> board = {{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
	printV(board);
	cout << "\t" << "|" << endl;
	cout << "\t" << "V" << endl;
	Solution sol;
	
	//ap;ply solve
	sol.solve(board);
	//print solutions
	printV(board);
	return 0;
}