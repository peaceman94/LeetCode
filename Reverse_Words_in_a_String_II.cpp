/*
186. Reverse Words in a String II
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
    void print(vector<char>& s)
    {
        for(auto x: s)
            cout << x;
        cout << endl;
        return;
    }

    void reverse_word(vector<char>& s, int l, int r)
    {
        while(l<r)
        {
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return;
    }
    
    void reverseWords(vector<char>& s) {
        //first reverse the entre vector
        reverse(s.begin(), s.end());

        //now reverse the individual words
        int prev = 0;
        for(int i =0; i<s.size(); i++)
        {
            //if it is a space, reverse
            if(s[i] == ' ')
            {
                reverse_word(s, prev, i-1);
                prev = i+1; 
            }
        };

        reverse_word(s, prev, s.size()-1);
        return;
    }
};

int main()
{
    vector<char> s = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    Solution sol;
    sol.reverseWords(s);
    for(auto x: s)
        cout << x;
    cout << endl;
    return 0;
};