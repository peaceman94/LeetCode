/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

#include<string>
#include<iostream>
#include <algorithm>
#include <vector> 
#include <unordered_map>

using namespace std;
class Solution {
public:

	int minSelf(int a, int b, int c){
		return(min(min(a,b),c));
	}
	//bottom up with matrix
	int minDistanceDPBottomUp1(string word1, string word2){
		int m = word1.size();
		int n = word2.size();

		int dp[m+1][n+1];
		
		for(int i=0; i<=m; i++){
			for(int j=0;j<=n;j++){
				if(i==0){
					dp[i][j] = j;
				}
				else if(j==0){
					dp[i][j]=i;
				}
				else if( word1[i-1] != word2[j-1] )
				{
					dp[i][j] = minSelf( dp[i-1][j-1], dp[i-1][j], dp[i][j-1] ) + 1;
				}
				else
				{
					dp[i][j] = dp[i-1][j-1];
				}
				//cout << i << " " << j << " " << dp[i][j] << endl;
			}
		}

		return dp[m-1][n-1];
	}

	//bottomup with no matrix
    int minDistanceDPBottomUp2(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();

		cout << m << " " << n << " " << word1 << "|" << word2 << endl;
		int dp_prev[n+1];
		int dp_curr[n+1];

		for(int i=0; i<=m; i++){
			for(int j=0;j<=n;j++){
				if(i==0){
					dp_curr[j] = j;
				}
		        else if(j==0){
					dp_curr[j]=i;
				}
				else if( word1[i-1] != word2[j-1] )
				{
					dp_curr[j] = minSelf( dp_prev[j-1], dp_prev[j], dp_curr[j-1] ) + 1;
				}
				else
				{
					dp_curr[j] = dp_prev[j-1];
				}
			};
			for(int k = 0; k<n+1; k++) dp_prev[k] = dp_curr[k];
		}
		return dp_curr[n];
	}
	
	//solution with memoisation
	unordered_map<string, int> map;
	int util( string word1, string word2, int m, int n){
		string key = to_string(m) + "_" + to_string(n);
		if(map.count(key))
			return(map[key]);
		if(m==0){ 
			map[key] = n;
			return(n);
		}
		if(n==0){
			map[key] = m;
			return m;
		}
		if(word1[m-1] == word2[n-1]){
			map[key] = util(word1, word2, m-1, n-1);
		}
		else{
			map[key] = minSelf( util(word1, word2, m-1, n-1), util(word1, word2, m, n-1), util(word1, word2, m-1, n) ) +1;
		}
		return(map[key]);
	}
	int minDistanceMemo(string word1, string word2){

		int m = word1.size();
		int n = word2.size();
		int d = util(word1, word2, m+1, n+1);
		return d;
	}

	//Solution to print the steps as well
		//bottom up with matrix
	void printSol( int *s, string word1, string word2){

	}
	int minDistanceDPBottomUp1WithSolution(string word1, string word2){
		int m = word1.size();
		int n = word2.size();

		int sol[m+1][n+1];
		//intialize a few rows/columns of sol
		sol[0][0] = -1;
		for(int i=1;i<=m;i++){
			sol[i][0] = 1;
		}
		for(int i = 1;i<=n;i++){
			sol[0][i] = 2;
		}

		int dp[m+1][n+1];
		
		for(int i=0; i<=m; i++){
			for(int j=0;j<=n;j++){
				if(i==0){
					dp[i][j] = j;
				}
				else if(j==0){
					dp[i][j]=i;
				}
				else if( word1[i-1] != word2[j-1] )
				{
					int temp = dp[i-1][j-1] < dp[i-1][j];
					if(temp){
						int temp2 = dp[i-1][j-1] < dp[i][j-1] ;
						if(temp2){
							sol[i][j] = 0;
						}
						else
						{
							sol[i][j] = 2;
						}
					}
					else
					{
						int temp2 = dp[i-1][j] < dp[i][j-1] ;
						if(temp2){
							sol[i][j] = 1;
						}
						else
						{
							sol[i][j] = 2;
						}

					}
					dp[i][j] = minSelf( dp[i-1][j-1], dp[i-1][j], dp[i][j-1] ) + 1;
 
				}
				else
				{
					dp[i][j] = dp[i-1][j-1]; //do nothing
					sol[i][j] = -1;
				}
				//cout << i << " " << j << " " << dp[i][j] << endl;
			}
		}
		//printSol(sol, word1, word2);
		//print solutions
		cout << "Min steps required: " << dp[m][n] << endl;
		int i = m; 
		int j = n;
		string temp;
		temp = word1;
		while(i>=0 && j>=0){
			string temp_prev = temp;
			int print = 0;
			switch(sol[i][j]){
				case 0:
					cout << "replace " << word1[i-1] << " with " << word2[j-1] << " at index " << i-1 << endl;
					temp[i-1] = word2[j-1];
					i--;
					j--;
					
					print = 1;
					break;
				case 1:
					cout << "delete: " << word1[i-1] << " at index " << i-1 << endl;
					temp.erase(i-1, 1);
					i--;
					print = 1;
					break;
				case 2:
					cout << "insert: " << word2[j-1] << " at index " << i-1 << endl;
					temp.insert(i, 1, word2[j-1]);
					j--;
					print = 1;
					break;
				case -1:
					i--;
					j--;
					break;
			}
			
			if(print) cout<< temp_prev << " ---> " << temp << endl << endl;
		}
		return dp[m-1][n-1];
	}

};

int main()
{
	string word1;
	string word2;

	cin >> word1 >> word2;

	Solution c;
	//int d = c.minDistanceDP2( word1, word2);
	//int d = c.minDistanceDP2( "", "a");
	//int d = c.minDistanceMemo( word1, word2);
	int d = c.minDistanceDPBottomUp1WithSolution( word1, word2);
	cout << "distance is " << d << endl;

	//cout << "oh! and btw the words are " << word1 << " " << word2 << "!" << endl;

	//the second way to take string input
	//getline(cin, word1);
	//cout << "second input is: " << word1 <<endl;
	return 0;
}