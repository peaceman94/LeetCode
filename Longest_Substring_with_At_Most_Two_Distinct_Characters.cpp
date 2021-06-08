/*
159. Longest Substring with At Most Two Distinct Characters
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
    //brute force method
    int lengthOfLongestSubstringTwoDistinctBrute(string s) {

        int max_size = 0;
        for(int i=0; i<s.size(); i++)
        {
            unordered_set<char> seen;
            int j_val = i;
            for(int j=i; j<s.size(); j++)
            {
                seen.insert(s[j]);
                j_val = j;
                if(seen.size() > 2)
                {
                    break;
                }
            }

            if(max_size <= j_val-i+1)
            {
                max_size = j_val-i+1;
            }
        }
        return max_size;
    }

    //sliding window method
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        int max_output = 0;
        int l = 0;
        int r = 0;

        int count = 0; //takes care of distinct count of elements
        unordered_map<char, int> count_char; //counts the char counts
        while(r < s.size() && l<=r)
        {
            if(count <= 2)
            {
                if(count_char.find(s[r]) == count_char.end())
                    count++;                   
                count_char[s[r]] += 1;
                
                //cout << l << ", " << r << ": " << s[r] << ": " << count_char[s[r]] << ", " << count << endl;
                //check if this is greater than the max
                if((max_output <= r-l+1) && (count <= 2 ) )
                {
                    //cout << "max found!!: " << l <<", " << r << endl;
                    max_output = r-l+1;
                }                
                
                r++;
                //cout << "incrementing r: " << r << endl;
            }
            else
            {
                while(count>2)
                {
                    if(count_char[s[l]] > 0) count_char[s[l]]--;
                    if(count_char[s[l]] == 0)
                    {
                        count_char.erase(s[l]); 
                        count--;
                    }

                    l++;
                    //cout << "incrementing l: " << l << endl;
                }
            }   
        }
        return max_output;
    }
};

int main()
{
    string s = "aabbbss";
    Solution sol;
    
    int output = sol.lengthOfLongestSubstringTwoDistinct(s);
    cout << "output is: " << output << endl;
    
    return 0;
}