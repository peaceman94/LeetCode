/*
221. Maximal Square

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/


#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
	//dp top-down solution
	int maximalSquare(vector<vector<char> >& matrix){
		int m = matrix.size();
		int n = (m>0) ? matrix[0].size():0;

		if(m==0 || n==0 ) return 0;

		int dp[n];
		int dp_prev[n];

		int maxlen = 0;

		for(int i=0; i<m; i++){
			for(int j = 0; j<n;j++){
				if(i == 0){
					dp[j] = (matrix[i][j] == '0') ? 0: 1; 
					if(dp[j] > maxlen) maxlen = dp[j];
					continue;
				}
				if(j==0){
					dp[j] = (matrix[i][j] == '0') ? 0: 1;
					if(dp[j] > maxlen) maxlen = dp[j];
					continue;
				}

				if(matrix[i][j] == '0') 
					dp[j] = 0;
				else
				{
					dp[j] = min( dp[j-1], min(dp_prev[j-1], dp_prev[j]) ) + 1;
				}				
				
				if(dp[j] > maxlen) maxlen = dp[j];
			}

			for(int k = 0; k<n; k++){
				dp_prev[k] = dp[k];
			}
		}
		return maxlen * maxlen;
	}

	//brute force solution
    int maximalSquareBrute(vector<vector<char> >& matrix){
    	int m = matrix.size();
    	int n = (m>0) ? matrix[0].size():0;

    	int maxlen = 0;
    	for(int i=0; i<m; i++){
    		for(int j=0; j<n; j++){
    			if(matrix[i][j] == '0') continue;
    			else
    			{
    				int len = 1;
    				bool flag = true;
    				while(i+len <m && j+len < n && flag){
	    				for(int iter = j; iter <= j + len; iter++){
		    					if(matrix[i+len][iter] == '0')
		    					{
		    						flag = false;
		    						break;
		    					}
		    			}

	    				for(int iter = i; iter <= i + len; iter++){
	    					if(matrix[iter][j+len] == '0'){
	    						flag = false;
	    						break;
	    					}
	    				}

	    				if(flag) len++;
	    			}

	    			if(len > maxlen) maxlen = len;
	    		}
			}
		} 

		return(maxlen * maxlen); 	

    }
};

int main(){
	//manual input
	vector<vector<char> > dungeon;
	for(int i = 0; i<4; i++){
		vector<char> vect;
		if(i == 0)
		{
			vect.push_back('1');vect.push_back('0');
			vect.push_back('1');vect.push_back('0');
			vect.push_back('0');		
		}
		else if(i==1)
		{
			vect.push_back('1');vect.push_back('0');
			vect.push_back('1');vect.push_back('1');
			vect.push_back('1');
		}
		else if(i==2)
		{
			vect.push_back('1');vect.push_back('1');
			vect.push_back('1');vect.push_back('1');
			vect.push_back('1');
		}
		else
		{
			vect.push_back('1');vect.push_back(0);
			vect.push_back('0');vect.push_back('1');
			vect.push_back('0');
		}
		dungeon.push_back(vect);
	}
	
	//
	Solution sol;
	//int output = sol.maximalSquareBrute(dungeon);
	int output = sol.maximalSquare(dungeon);
	cout << "Output is: " << output << endl;
	return 0;
}