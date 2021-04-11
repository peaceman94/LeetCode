/*
399. Evaluate Division
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.
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
	unordered_map<string, vector<pair<string, double>>> graph;

	void createGraph( vector<vector<string>>& equations, vector<double>& values )
	{
		for(int i =0; i<equations.size(); i++)
		{
			vector<string> curr_eq = equations[i];
			graph[curr_eq[0]].push_back( { curr_eq[1], values[i] });
			graph[curr_eq[1]].push_back( { curr_eq[0], 1/values[i] });
		}
		return;
	}

	void printGraph()
	{
		for(auto x: graph)
		{
			cout << x.first << ":  ";
			for(auto y: x.second)
			{
				cout << y.first <<  " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

	//dfs
	double DFS(string start, string end, vector<string> &visited, bool verbose)
	{
		if(verbose) cout << start << " to " << end << endl;
		if(graph.find(start) == graph.end())
		{
			return -1.0; //if node doesnt exist return;
		} 
		
		if(start == end)
		{
			return 1.0; //if found return
		} 
				
		//pull the neighbors
		auto nbors = graph[start];
		if(verbose) cout << "nbors size: " << nbors.size() <<  " ,nbors: ";

		//all nbors
		if(verbose)
		{
			for(auto nbor: nbors)
			{	
				cout << nbor.first << " ";
			}
			cout << endl;

		}
	
 		for(auto nbor: nbors)
		{
			if( find(visited.begin(), visited.end(), nbor.first) != visited.end() ) continue;

			//update the answer and mark the node to be visited
			visited.push_back(nbor.first);
			double dfs_output = DFS(nbor.first, end, visited, verbose);
			if( dfs_output != -1.0 )
			{
				if(verbose) cout << "yay answer is " << nbor.second * dfs_output << endl;
				return nbor.second * dfs_output;
			}
			//back tracking
			visited.pop_back();
		};

		return -1.0;
	}

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> output;
        bool verbose = false;
        //need a graph with weights
        createGraph(equations, values);
        if(verbose) printGraph();

        //need to have find, union operation on it
        for(int i=0; i<queries.size(); i++)
        {
        	double answer = 1.0;
        	vector<string> visited = { queries[i][0] };
        	answer = DFS(queries[i][0], queries[i][1], visited, verbose);
        	output.push_back( answer );
        }
        return output;
    }
};

int main()
{
	vector<vector<string>> equations = {{"a","b"},{"b","c"}};
	vector<double> values = {2.0,3.0};
	vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

	Solution sol;
	auto output = sol.calcEquation(equations, values, queries);
	for(auto x: output) cout << x << " \t";
	cout << endl;
	return 0;
}