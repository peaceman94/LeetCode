/*
542. 01 Matrix

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 

Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right
*/
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include <utility>
#include<queue>
using namespace std;
class Solution {
public:
	//utility to print matrix
	void printMatrix( vector<vector<int>>& mat )
	{
		for(int i=0; i<mat.size(); i++)
		{
			for(int j=0; j<mat[i].size(); j++)
			{
				cout << mat[i][j] << "\t";
			}
			cout << endl;
		}
	}

	//naive BFS - I feel stupid!
	string createKey(int i, int j)
	{
		string key1 = to_string(i) + "_" + to_string(j);
		return key1;
	}
	
	auto createEdges( vector<vector<int>>& matrix )
	{
		unordered_map<string, vector<pair<int, int>>> e;
		for( int i=0; i<matrix.size(); i++)
        {
        	for(int j=0; j<matrix[i].size(); j++ )
        	{
        		vector<pair<int, int>>val;
        		string key = createKey(i, j);
        		if(i-1>=0)
        		{
        			pair<int, int> p = make_pair(i-1,j);
        			val.push_back( p );
        		}
        		if(i+1< matrix.size())
        		{
        			pair<int, int> p = make_pair(i+1, j);
        			val.push_back( p );
        		}
        		if(j-1 >= 0)
        		{
        			pair<int, int> p = make_pair(i, j-1);
        			val.push_back( p );
        		}

        		if(j+1 < matrix[i].size())
        		{
        			pair<int, int> p = make_pair(i, j+1);
        			val.push_back( p );
        		}
        		e[key] = val;
        	}
        }
        return e;
	}

	int bfs( unordered_map<string, vector<pair<int, int> > >& e, vector<vector<int>>& matrix, int i, int j )
	{
		string s = createKey(i, j);
		vector<string> q{s};
		
		unordered_map<string, bool> visited;
		visited[s] = true;
		
		int lev = 1;
		while(q.size())
		{
			vector<string> curr;
			for(int i = 0; i< q.size(); i++)
			{
				string curr_node = q[i];
				vector<pair<int, int>> nbr = e[curr_node];
				for(int j=0; j<nbr.size(); j++)
				{
					pair<int, int>p = nbr[j];
					string nbr_j = createKey(p.first, p.second);

					if(visited.find(nbr_j) == visited.end())
					{
						curr.push_back(nbr_j);
						visited[nbr_j] = true;
						if(matrix[p.first][p.second] == 0)
							return lev;
					}		
				}
			}
			q = curr;
			lev++;
		}
		
		return 0;
	}
    vector<vector<int>> updateMatrixNaiveBFS(vector<vector<int>>& matrix) {
    	if(matrix.size() == 0) return matrix;
        
        //create edges
        auto e = createEdges(matrix);

        vector<vector<int>> output(matrix.size(), vector<int>(matrix[0].size(), 0));
        for( int i=0; i<matrix.size(); i++)
        {
        	for(int j=0; j<matrix[i].size(); j++ )
        	{
        		if(matrix[i][j] == 1)
        		{
        			output[i][j] = bfs(e, matrix, i, j);
        		}
        	}
        }
        return output;
    }

    //bfs cool soln
    vector<vector<int>> updateMatrixBFS(vector<vector<int>>& matrix) {
    	vector<vector<int>> output;
    	if(matrix.size() == 0)
    		return output;
    	
    	int m = matrix.size();
    	int n = matrix[0].size();

    	vector<vector<int>> d(m, vector<int>(n, INT_MAX));
    	//queue
    	queue<pair<int, int>> q;

    	//push all the zeros
    	for(int i =0 ; i<m; i++)
    	{
    		for(int j=0; j<n; j++)
    		{
    			if(matrix[i][j] == 0)
    			{
    				q.push({i,j});
    				d[i][j] = 0;
    			}
    		}
    	}

    	int ref[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    	while(!q.empty())
    	{
    		//pop the front element
    		pair<int, int> p = q.front();
    		q.pop();
    		
    		for(int i=0; i<4; i++)
    		{
    			int l = p.first + ref[i][0];
    			int r = p.second + ref[i][1];

    			if(l>=0 && r >= 0 && l < m && r < n)
    			{
    				if(d[l][r] > d[p.first][p.second] + 1)
    				{
    					d[l][r] = d[p.first][p.second] + 1;
    					q.push({l,r});
    				}
    			}
    		}
    	}
    	return d;
    }

    //DP solution
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    	
    	if(matrix.size() == 0)
    	{
    		vector<vector<int>> output;
    		return output;
    	}
    	
    	int m = matrix.size();
    	int n = matrix[0].size();

    	vector<vector<int>> d(m, vector<int>(n, INT_MAX));

    	//push all the zeros with distance zero
    	//apply 2 scans:
    	//scan1:

    	for(int i =0 ; i<m; i++)
    	{
    		for(int j=0; j<n; j++)
    		{
    			if(matrix[i][j] == 0)
    			{
    				d[i][j] = 0;
    			}
    			else
    			{
    				if( i == 0 && j!=0  )
    				{
    					d[i][j] = min(d[i][j], d[i][j-1]+ 1 );
    				}
    				else if( i != 0 && j==0 )
    				{
    					d[i][j] = min(d[i][j],  d[i-1][j] + 1 );
    				}
    				else
    				{
    					d[i][j] = min(d[i][j], min(d[i-1][j], d[i][j-1]) + 1 );	
    				}
    			}
    		}
    	}

    	//scan 2:
    	for(int i =m-1 ; i>=0; i--)
    	{
    		for(int j=n-1; j>=0; j--)
    		{	
    			if(matrix[i][j] == 0) continue;
    			if(i==m-1 && j == n-1 ) continue;
    			if( i==m-1 && j != n-1)
    			{
    				d[i][j] = min(d[i][j], d[i][j+1] + 1 );	
    			}
    			else if( i!=m-1 && j == n-1)
    			{
    				d[i][j] = min(d[i][j], d[i+1][j] + 1 );	
    			}
    			else
    			{
					d[i][j] = min(d[i][j], min(d[i+1][j], d[i][j+1]) + 1 );	
    			}
    		}
    	}
    	return d;
    }	

};

int main()
{
	vector<vector<int>> mat{{0,0,0}, {0,1,0}, {1,1,1}};
	Solution sol;
	vector<vector<int>> output = sol.updateMatrix(mat);
	sol.printMatrix(mat);
	cout << endl;
	sol.printMatrix(output);
	return 0;
}