/*
115. Distinct Subsequences

Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without 
disturbing the relative positions of the remaining characters. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It's guaranteed the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

0 <= s.length, t.length <= 1000
s and t consist of English letters.

*/
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
	unordered_map<string,int> map;
	int util( string s, string t, int m, int n){
		string key = to_string(m) + "_" + to_string(n);
		if(map.count(key))
			return(map[key]);
		int output = 0;

		if(n==0) return 1;
		if(m==0) return 0;
		
		if(s[m-1] != t[n-1]){
			output += util(s,t, m-1, n);
		}

		else{
			output += util(s, t, m-1, n-1);
			output += util(s,t, m-1, n);
		}
		map[key] = output;
		//cout << "m: " << m << " n: " << n << " output: " << output << endl;
		return output;
	}
public: 
    int numDistinct(string s, string t) {
    	int m = s.size();
    	int n = t.size();

    	int output = util(s,t, m, n);
        return output;
    }


    int numDistinctBU(string s, string t){
    	int m = s.size();
    	int n = t.size();

    	//initialize dp map
    	//long long int map[m+1][n+1];
    	vector<vector<long> > map(m+1,vector<long>(n+1,0));

    	for(int i = 0; i<= n; i++){
    		map[0][i] = 0;
    	}
    	
    	for(int i = 0; i<= m; i++){
    		map[i][0] = 1;
    	} 

       	//start populating bottom up
       	for(int i=1;i<=m;i++){
       		for(int j=1;j<=n;j++){
				if(s[i-1]!= t[j-1]){
					map[i][j] = map[i-1][j];
				}
				else
				{
					map[i][j] += map[i-1][j-1]; 
					map[i][j] += map[i-1][j];
				}
				cout << "i: " << i << " j: " << j << " map: " << map[i][j] << endl;
    		}
    	}
    	return (int) map[m][n];
    }
};

int main(){
	string s;
	string t;
	cin >> s >> t;
	Solution sol;
	//int out = sol.numDistinct(s,t);
	int out = sol.numDistinctBU(s,t);
	cout << "Solution is: " << out << endl;
	return 0;
}