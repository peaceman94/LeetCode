/*
161. One Edit Distance
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
    bool helper(string s, string t, int s_ind, int t_ind, bool isModificationAllowed)
    {
        //boundary conditions
        if(s_ind == s.size())
        {
            if( (t_ind == t.size() ) || (isModificationAllowed && (t_ind == t.size() - 1 )) )
                return true;
            
            return false;
        }

        //same first characheters
        if(s[s_ind] == t[t_ind])
            return helper(s, t, s_ind+1, t_ind+1, isModificationAllowed);
        
        //delete the current character from s
        if(isModificationAllowed)
        {
            bool output1 = helper(s, t, s_ind+1, t_ind, false);
            if(output1) return true;
            
            //insert the current char
            output1 = helper(s, t, s_ind, t_ind+1, false);
            if(output1) return true;

            //replace the 
            output1 = helper(s, t, s_ind+1, t_ind+1, false);
            if(output1) return true;

        }
        return false;
    }

    bool isOneEditDistance(string s, string t) {
        if(s == t) return false;
        bool output = helper(s, t, 0, 0, true);
        return output;
    }
};

int main()
{
    string s = "abe";
    string t = "abc";

    Solution sol;
    bool output = sol.isOneEditDistance(s, t);
    cout << "output is: " << output  << endl;
};



