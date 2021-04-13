/*
1529. Bulb Switcher IV
There is a room with n bulbs, numbered from 0 to n-1, arranged in a row from left to right. Initially all the bulbs are turned off.

Your task is to obtain the configuration represented by target where target[i] is '1' if the i-th bulb is turned on and is '0' if it is turned off.

You have a switch to flip the state of the bulb, a flip operation is defined as follows:

Choose any bulb (index i) of your current configuration.
Flip each bulb from index i to n-1.
When any bulb is flipped it means that if it is 0 it changes to 1 and if it is 1 it changes to 0.

Return the minimum number of flips required to form target.

 

Example 1:

Input: target = "10111"
Output: 3
Explanation: Initial configuration "00000".
flip from the third bulb:  "00000" -> "00111"
flip from the first bulb:  "00111" -> "11000"
flip from the second bulb:  "11000" -> "10111"
We need at least 3 flip operations to form target.
Example 2:

Input: target = "101"
Output: 3
Explanation: "000" -> "111" -> "100" -> "101".
Example 3:

Input: target = "00000"
Output: 0
Example 4:

Input: target = "001011101"
Output: 5
 

Constraints:

1 <= target.length <= 10^5
target[i] == '0' or target[i] == '1'
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

class Solution {
public:
    void flip(string &s, int start)
    {
        for(int i=start; i<s.size();i++)
        {
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        return;
    }
    int minFlipsTLE(string target) {
        int flip_count = 0;

        string s (target.size(), '0');
        for(int i = 0 ; i < s.size(); i++)
        {
            while(s[i] == target[i] && i<s.size())
            {
                i++;
            };

            if(i>=s.size()) break;

            flip_count++;
            flip(s,i);
        };
        return flip_count;
    }

    int minFlips(string target) {
        int n = target.size();
        string s(n, '0');

        int flip_count = 0;
        for(int i=0; i<n; i++)
        {
            while(s[i] == target[i] && i<n) i++;
            
            //check if we have something to process
            if(i>=n) break;

            //not find the first element which is same
            flip_count++;
            while(s[i] != target[i] && i<n) i++;
            
            if(i>=n) break;
            
            //again increase it to be in line with 
            flip_count++;
        }
        return flip_count;
    }    
};

int main()
{
    string target = "001011101";
    Solution sol;
    int output = sol.minFlips(target);
    cout << output << endl;
    return 0;
}