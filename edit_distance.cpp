/*
72. Edit Distance
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

class Solution {
public:
    int distHelper(string &s, string &t, int s_ind, int t_ind,  unordered_map<string, int> &cache)
    {
        //boundary conditions
        if(s_ind == s.size())
        {
            return t.size() - t_ind;
        }

        if(t.size() == t_ind)
        {
            return s.size() - s_ind;
        }

        //check cache
        string key = to_string(s_ind) + "_" + to_string(t_ind);
        if(cache.find(key) != cache.end())
            return cache[key];

        //if current is same move on
        if(s[s_ind] == t[t_ind])
            return distHelper(s, t, s_ind+1, t_ind+1, cache);
        
        //insert a character
        int d1 = 1 + distHelper(s, t, s_ind, t_ind+1, cache);
        
        //delete a character
        int d2 = 1 + distHelper(s, t, s_ind+1, t_ind, cache);
        
        //replace a character
        int d3 = 1 + distHelper(s, t, s_ind+1, t_ind+1, cache);

        //take the minimum
        int output = min(d1, min(d2, d3));
        return cache[key] = output;
    }
    int minDistance(string word1, string word2) {
        unordered_map<string, int> cache;
        int output = distHelper(word1, word2, 0, 0, cache);
        return output;
    }
};

int main()
{
    string s = "intention";
    string t = "execution";

    Solution sol;
    int output = sol.minDistance(s, t);
    cout << "output is: " << output  << endl;
};


