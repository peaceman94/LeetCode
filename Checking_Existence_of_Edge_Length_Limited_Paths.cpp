/*
1697. Checking Existence of Edge Length Limited Paths

An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes.

Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .

Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, and false otherwise.

 

Example 1:


Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
Output: [false,true]
Explanation: The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
For the second query, there is a path (0 -> 1 -> 2) of two edges with distances less than 5, thus we return true for this query.
Example 2:


Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
Output: [true,false]
Exaplanation: The above figure shows the given graph.
 

Constraints:

2 <= n <= 105
1 <= edgeList.length, queries.length <= 105
edgeList[i].length == 3
queries[j].length == 3
0 <= ui, vi, pj, qj <= n - 1
ui != vi
pj != qj
1 <= disi, limitj <= 109
There may be multiple edges between two nodes.
*/
#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include <numeric>
#include <algorithm>
#include <queue>
#include <limits>
#include <climits>
using namespace std;

/*
class Solution {
public:
    void printGraph(vector<unordered_map<int, int>> &graph)
    {
        for(int i=0 ; i<graph.size(); i++)
        {
            for(auto x: graph[i])
            {
                cout << i << "|" << x.first << ": " << x.second << endl;
            }
        }
        return;
    }

    //creates the graph as a matrix which isnt very efficient
    vector<unordered_map<int, int>> createGraph(int n, vector<vector<int>>& edgeList)
    {
        vector<unordered_map<int, int>> graph(n);
        for(auto edge: edgeList)
        {
            int start = edge[0], end = edge[1], wt = edge[2];
            if(graph[start].find(end) == graph[start].end()) graph[start][end] = wt;
            else graph[start][end] = min(graph[start][end], wt);
            graph[end][start] = graph[start][end];
        }

        //printGraph(graph);
        return graph;
    }

    bool DFS(int start, int end, int limit, vector<unordered_map<int, int>> &graph, vector<int> &visited)
    {
        //cout << "exploring . . . " << start << endl;
        if(start == end) return true;
        bool output = false;

        for(auto nbor: graph[start])
        {
            if(nbor.second >= limit) continue; //if limit is breached
            if(visited[nbor.first] == 1) continue; //if already visited
            //cout << "weight for " << start << " to " << j << " is " << graph[start][j] << endl;
            visited[nbor.first] = 1;  //mark the node visited
            output = output || DFS(nbor.first, end, limit, graph, visited);
        }
        return output;
    };

    //DFS works but time limit exceeded
    vector<bool> distanceLimitedPathsExistDFS(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        auto graph = createGraph(n, edgeList);
        vector<bool> output;        
        for(auto qry: queries)
        {
            vector<int> visited(n, 0);
            visited[qry[0]] = 1;
            output.push_back( DFS(qry[0], qry[1], qry[2], graph, visited) );
        }

        return output;
    }

    //DFS works but time limit exceeded
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> output(queries.size(), false);
        union_find uf(n);
        
        //make set
        for(int i=0; i<n; i++) uf.make_set(i);
        
        int t = 0;
        for(auto &q: queries) q.push_back(t++);
        
        //sort the edgelist by weight
        sort(queries.begin(),queries.end(),[](vector<int> &a,vector<int> &b){return a[2]<b[2];});
        sort(edgeList.begin(),edgeList.end(),[](vector<int> &a,vector<int> &b){return a[2]<b[2];});
        
        int ied = 0;
        int nel = edgeList.size();
        int start, end, limit, idx;
        vector<int> edge;
        bool curr_output;

        for(auto query: queries)
        {
            start = query[0], end = query[1], limit = query[2], idx = query[3];
            while(ied < nel)
            {
                edge = edgeList[ied];
                if(edge[2] >= limit) break;
                uf.union_do( uf.find_key( edge[0] ), uf.find_key(edge[1])  );
                ied++;
            };

            if(uf.find_key(start) == uf.find_key(end))  curr_output = true;
            output[idx] = curr_output;
        };
        return output;
    }
};
*/

class union_find
{
public:
	vector<int> parent;
	vector<int> rank;
	union_find(int n)
	{
		vector<int> temp(n, -1);
		parent = temp;

		vector<int> temp2(n, -1);
		rank = temp2;
	}

	void make_set(int i)
	{
		parent[i] = i;
		rank[i] = 1;
	}

	int find_key(int i)
	{
		if(i == parent[i]) return i;

		//parent[i] = find_key(parent[i]);
		//return parent[i];
        return(find_key(parent[i]) );
	}

	void union_do(int i, int j)
	{
		int root_1 = find_key(i);
		int root_2 = find_key(j);
		if(root_1 == root_2) return;
        
		if(rank[root_1] > rank[root_2])
		{
			parent[root_2] = root_1;
		}
		else
		{
			parent[root_1] = root_2;
            
			if(rank[root_1] == rank[root_2])
			{
				rank[root_2] += 1; 
			}
		}
        
        return;
	}
};

class Solution {
public:
    //DFS works but time limit exceeded
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        union_find uf(n);
        
        //make set
        for(int i=0; i<n; i++) uf.make_set(i);
        
        int t = 0;
        for(auto &q: queries) q.push_back(t++);
        
        //sort the edgelist by weight
        sort(queries.begin(),queries.end(),[](vector<int> &a,vector<int> &b){return a[2]<b[2];});
        sort(edgeList.begin(),edgeList.end(),[](vector<int> &a,vector<int> &b){return a[2]<b[2];});
        
        int ied = 0;
        int nel = edgeList.size();
        int start, end, limit, idx;
        vector<int> edge;
        bool curr_output;

        vector<bool> output(queries.size(), false);
        for(auto &query: queries)
        {
            start = query[0], end = query[1], limit = query[2], idx = query[3];
            while(ied < nel)
            {
                edge = edgeList[ied];
                if(edge[2] >= limit) break;
                uf.union_do( edge[0], edge[1] );
                ied++;
            };

            if(uf.find_key(start) == uf.find_key(end)) 
            {
                curr_output = true;
            };

            output[idx] = curr_output;
        };
        return output;
    }
};

int main()
{
    int n;
    vector<vector<int>> edgeList;
    vector<vector<int>> queries;

    //n = 3;
    //edgeList = {{0,1,2},{1,2,4},{2,0,8},{1,0,16}};
    //queries = {{0,1,2},{0,2,5}};

    n = 5;
    edgeList = {{0,1,10},{1,2,5},{2,3,9},{3,4,13}};
    queries = {{0,4,14},{1,4,13}};
    Solution sol;
    vector<bool> output = sol.distanceLimitedPathsExist(n, edgeList, queries);
    for(auto x: output) cout << x << " ";
    cout << endl;
    return 0;
}