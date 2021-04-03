/*
797. All Paths From Source to Target

Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1, and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

Example 1:


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Example 2:


Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
Example 3:

Input: graph = [[1],[]]
Output: [[0,1]]
Example 4:

Input: graph = [[1,2,3],[2],[3],[]]
Output: [[0,1,2,3],[0,2,3],[0,3]]
Example 5:

Input: graph = [[1,3],[2],[3],[]]
Output: [[0,1,2,3],[0,3]]
 

Constraints:

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i (i.e., there will be no self-loops).
The input graph is guaranteed to be a DAG.
*/

#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

class Solution {
public:
	vector<vector<int>> result;
	void DFS(vector<vector<int>>& graph, int n, vector<bool> &visited, vector<int> &curr_path)
	{
		//cout << "visiting: " << n << endl;
		if(n == graph.size()-1) 
		{
			result.push_back(curr_path);
			return;
		};

		for(int i = 0; i<graph[n].size(); i++)
		{	
			if(!visited[graph[n][i]])
			{
				visited[graph[n][i]] = true;
				curr_path.push_back(graph[n][i]);
				DFS(graph, graph[n][i], visited, curr_path);
				curr_path.pop_back();
				visited[graph[n][i]] = false;
			};
		}
		return;
	}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    	vector<bool> visited(graph.size(), false);
    	vector<int> curr_path = {0};
    	DFS(graph, 0, visited, curr_path);
    	return result;
    }
};

int main()
{
	//vector<vector<int>> graph = {{1,2},{3},{3},{}};
	vector<vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};
	Solution sol;
	auto output = sol.allPathsSourceTarget(graph);

	cout << "output is: " << endl;
 	for(auto x: output)
	{
		for(auto y:x) cout << y << " ";
		cout << endl;
	}

	return 0;
}