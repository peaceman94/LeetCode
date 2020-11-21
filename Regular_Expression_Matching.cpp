/*
10. Regular Expression Matching

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input: s = "mississippi", p = "mis*is*p*."
Output: false
 

Constraints:

0 <= s.length <= 20
0 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string pattern(string p, int ind){
        if(ind >= p.size())
        {   
            return("");
        }
        if(ind == p.size()-1){
            return(p.substr(ind, 1));
        }
        if(p[ind+1] == '*')
        {
            return(p.substr(ind, 2));
        }
        else
        {
            return(p.substr(ind, 1));
        }
    };

    bool isMatchHelper(string s, string p, int l, int r) {

        //base cases
        if(l==s.size() && r == p.size()) return true;  //both the string and pattern have ended

        //if string is empty but pattern remains
        if(l == s.size())
        {
            while( r < p.size() )
            {
                string pat = pattern(p, r);
                if(pat.size() == 1 ) return false;
                r += 2;
            }
            return true;
        }

        //if string remains but pattern empties
        if( r == p.size()) return false;

        //actual code starts
        while(l< s.size() && r<p.size())
        {
            string pat = pattern(p, r);
            //cout << "l,r is: " << l << "," <<r << " Pattern is: " << pat << endl << endl;
            
            //case 1: pattern is d.
            if(pat.size() == 1)
            {
                //case 1.1: Pattern is '.'
                if(pat == ".")
                {
                    return(isMatchHelper(s, p, ++l, ++r));
                }
                //case 1.2: pattern is 'd'
                else
                {
                    if(pat == s.substr(l, 1))
                    {   
                        return(isMatchHelper(s, p, ++l, ++r));
                    } 
                    else
                    {
                        return false;
                    }
                }
            }
            //case 2: patterns like 'd*' or '.*'
            else if( pat.size() == 2)
            {
                bool curr_mat;
                //case 2.1: pattern is '.*'
                if(pat ==  ".*" )
                {
                    //skip the same pattern to avoid recursion in case of .*
                    string nxt_pat = pattern(p, r+2);
                    while(nxt_pat == pat)
                    {
                        //cout << "next_pat " << nxt_pat << endl;
                        r += 2;
                        nxt_pat = pattern(p, r+2);   
                    }

                    //cout << "here .*" << endl;
                    //cout << l << " " << r << endl;
                    curr_mat = isMatchHelper(s, p, l+1, r) || isMatchHelper(s, p, l, r+2);
                    
                }
                //case 2.2: pattern is 'd*'
                else
                {
                    //skip the same pattern to avoid recursion in case of d*
                    string nxt_pat = pattern(p, r+2);
                    while(nxt_pat == pat)
                    {
                        r += 2;
                        nxt_pat = pattern(p, r+2);   
                    }
                    //take a look into next pattern
                    if(s[l] == p[r])
                    {
                        bool curr_mat1 = isMatchHelper(s, p, l+1, r);
                        bool curr_mat2 = isMatchHelper(s, p, l, r+2);
                        curr_mat = curr_mat1 || curr_mat2;
                        
                    }
                    else                    
                    {
                        curr_mat = isMatchHelper(s, p, l, r+2);
                    }
                }
                return curr_mat;
                
            }
        }

        return l == s.size() && r == p.size();
    }

    bool isMatchKhandes(string s, string p){
        return( isMatchHelper (s, p, 0, 0) );
    }
};

int main(){
    string s = "bbbba";
    //string s = "aaaaaaaaaaaaab";
    string p = ".*a*a";

    Solution sol;
    int output = sol.isMatchKhandes(s,p);
    //string output = sol.pattern(p, 11);
    cout << "output is: " << output << endl;
    return 0;
}