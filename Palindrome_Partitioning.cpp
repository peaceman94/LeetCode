/*
131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
A palindrome string is a string that reads the same backward as forward.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]

Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
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
    void printVectOfVectStr(vector<vector<string>> v)
    {
        for(auto x:v)
        {
            cout << "___________________" << endl;
            for(auto y:x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
    };

    bool isPalindrome(string &s, int start, int end )
    {
        while(start <= end)
        {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> helper(string &s, int start, int end, unordered_map<string, vector<vector<string>> > &map )
    {
        //cout << start << "," << end << endl;
        string key = to_string(start) + "_" + to_string(end);
        if(map.find(key) != map.end()) return(map[key]);

        vector<vector<string>> output = {};

        //extreme condition
        if(start > end ) return output;
        
        //single letter word
        if(start == end)
        {
            output.push_back( { s.substr(start, 1) });
            return map[key] = output;
        }

        //2 letter word
        if(start + 1 == end)
        {
            output.push_back( { s.substr(start, 1), s.substr(end, 1), } );
            if(s[start] == s[end]) output.push_back( {s.substr(start, 2)} );  
            return map[key] = output;
        };

        if(isPalindrome(s, start, end)) output.push_back( {s.substr(start,  end-start+1) } );
        for(int i=start; i<end; i++)
        {
            if(!isPalindrome(s, start, i)) continue;
            string sorry_next = s.substr(start, i-start+1);
            vector<vector<string>> output_2 = helper(s, i+1, end, map);
            for(auto &x: output_2) x.insert(x.begin(), sorry_next);
            output.insert( output.end(), output_2.begin(), output_2.end() );
        }

        return map[key] = output;
    }

    //LOL: this is so brute BUT it gets accepted in the leetcode! rofl !
    vector<vector<string>> partition(string s) {
        unordered_map<string, vector<vector<string>> > map;
        vector<vector<string>> output = helper(s, 0, s.size()-1, map);
        return output;
    }

};

int main()
{
    string s = "aab";
    Solution sol;
    vector<vector<string>> output = sol.partition(s);
    cout << "output is: " << endl;
    sol.printVectOfVectStr(output);
    return 0;
}