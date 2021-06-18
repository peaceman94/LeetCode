/*
983. Minimum Cost For Tickets
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
#include <map>

using namespace std;

struct compare {
    inline bool operator()(const std::string& first,
            const std::string& second) const
    {
        return first.size() < second.size();
    }
};

class Solution {
public:
    bool checkRelated(string a, string b)
    {
        int diff = a.size() - b.size();
        if(abs(diff) != 1) return false;
        if(diff>0) swap(a,b);

        int i=0, j=0;
        bool flag = true;
        while(i<a.size())
        {
            if(a[i] == b[j])
            {
                i++;
                j++;
                continue;
            }
            else if(flag == true)
            {
                j++;
                flag = false;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    int DFS(string root, unordered_map<string, vector<string>> &graph, 
                        unordered_map<string, int> &cache)
    {
        if(cache.find(root) != cache.end())
            return cache[root];
        
        int count = 1;
        if(graph.find(root) == graph.end()) return cache[root] = count;
        
        for(auto nbor: graph[root])
        {
            int curr_count = 1 + DFS(nbor, graph, cache);
            if(curr_count > count)
                count = curr_count;
        }
        //cout << root << " " << count << endl;
        return cache[root] = count;
    };

    int longestStrChain(vector<string>& words) {
        unordered_map<string, vector<string>> graph;
        for(int i=0; i<words.size(); i++)
        {
            for(int j=i+1; j<words.size(); j++)
            {
                if(checkRelated(words[i], words[j]))
                {
                    if(words[i].size() < words[j].size())
                        graph[words[i]].push_back(words[j]);
                    else
                        graph[words[j]].push_back(words[i]);
                }
            }
        }

        //print graph
        /*
        for(auto t: graph)
        {
            auto str = t.first;
            auto nbor = t.second;
            cout << str << ": " ;
            for(auto x: nbor)
                cout <<  x << " ";
            cout << endl;
        }
        */
        int output = 0;
        unordered_map<string, int> cache;
        for(int i=0; i<words.size(); i++)
        {
            int curr_output = DFS(words[i], graph, cache);
            if(curr_output > output)
                output = curr_output;
        }
        return output;
    }
};

int main()
{
    vector<string> words = {"aasdfasdfg","b","ba","bca","bda","bdca"};
    //words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    //["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"]
    Solution sol;
    auto output = sol.longestStrChain(words);
    cout << output << endl;
    return 0;
}