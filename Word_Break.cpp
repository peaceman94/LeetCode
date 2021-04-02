/*
139. Word Break
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
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

using namespace std;

class Solution {
public:
    bool helper(string &s,  int start, unordered_set <string> &stringSet, unordered_map<string, bool> &map)
    {
        if(map.find(s.substr(start)) != map.end()) return map[s.substr(start)];

        //cout << "Start is: "<<start << endl;
        bool output = false;
        if(start >= s.size())
        {
            //do boundary condition
            return true;
        }
        for(int end=start; end<s.size(); end++)
        {
            string curr_word = s.substr(start, end-start+1);

            //if the word b/w start and end is in dictionary proceed, else you know, no point
            if(stringSet.find(curr_word) == stringSet.end()) continue;
            output = output || helper(s, end+1, stringSet, map );

            //cout << "curr_word is; " << curr_word << endl;
            //cout << "output is; " << output << endl;

            if(output) return map[s.substr(start)] = output;
        }
        return map[s.substr(start)] = output;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> stringSet;
        for(auto x:wordDict) stringSet.insert(x);
        //create unordered map
        unordered_map<string, bool>  map;
        bool output = helper(s,0, stringSet, map);
        return output;
    }
};


int main()
{
    string s = "leetcode";
    vector<string> dict = {"leet", "code"};
    Solution sol;
    bool output =  sol.wordBreak(s, dict);
    cout << "output is: " << output << endl;
    return 0;
}