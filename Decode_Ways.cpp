/*
91. Decode Ways
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with '0'. We cannot ignore a zero when we face it 
while decoding. So, each '0' should be part of "10" --> 'J' or "20" --> 'T'.
Example 4:

Input: s = "1"
Output: 1
 

Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/

#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:

    int numDecodings(string s) {
    	int dp[s.size()+1];
    	dp[0] = 1;
    	
    	for(int i=1; i<= s.size(); i++){
    		dp[i] = 0;
    		int singleNumber = stoi(s.substr(i-1, 1));
    		if(singleNumber > 0){ dp[i] += dp[i-1]; };

    		int doubleNumber = (i>1) ? stoi(s.substr(i-2, 2)): 100;
    		if( (doubleNumber >= 10 ) && (doubleNumber <= 26) ) { dp[i] += dp[i-2]; };
    	}
        return dp[s.size()];
    }

};

int main(){

	string s;
	cin >> s;
	Solution sol;

	int output = sol.numDecodings(s);
	cout << "Total decodings is: " << output<<endl;
	return 0;
}