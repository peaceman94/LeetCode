/*
207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 
Constraints:

1 <= numCourses <= 105
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
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
    void printCharMat(vector<vector<int>> grid)
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

    unordered_map<int, vector<int>> edges;
    void createEdges(vector<vector<int>>preq)
    {
        for(int i=0; i<preq.size(); i++)
        {
            edges[preq[i][1]].push_back(preq[i][0]);
        }
        return;
    }

    vector<int> createInDegrees( int n)
    {
        vector<int> output(n, 0);
        for(auto i=edges.begin(); i!=edges.end();i++)
        {
            for(int j:i->second )
            {
                output[j]++;
            }   
        }
        return output;
    }

    bool applyBFS(vector<int> &inDegrees )
    {
        vector<int> visited(inDegrees.size(), 0);
        queue<int> q;
        
        for(int i=0; i<inDegrees.size();i++)
        {
            if(inDegrees[i] != 0) continue;
            q.push(i);
            visited[i] = 1;
        };
        
        //explore each vertex and see if there is a cycle - if yes we are in trouble
        while(q.size())
        {
            int node = q.front();
            q.pop();

            //get all nbors for node
            vector<int> nbors = edges[node];
            for(auto x: nbors)
            {
                if(!visited[x])
                {
                    inDegrees[x]--;
                    if(inDegrees[x] == 0)
                    {
                        q.push(x);
                        visited[x] = 1;
                    }
                }
            }
        };

        for(int i=0; i<inDegrees.size();i++)
        {
            if(inDegrees[i] != 0) return false;
        };
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        createEdges(prerequisites);
        vector<int> inDegrees = createInDegrees(numCourses);
        
        bool output = applyBFS(inDegrees);
        return output;
    }
};

int main()
{
    int n = 4;
    vector<vector<int>> prerequisites = {{1,0}, {2,0}, {3,1}, {3,2}};
    Solution sol;
    sol.printCharMat(prerequisites);
    bool output = sol.canFinish(n, prerequisites);
    cout << "output is " << output << endl;
    return 0;
}