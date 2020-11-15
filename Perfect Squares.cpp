/*
Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

#include<iostream>
#include<cmath>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
	//for some wierd reason, top down approach does TLE in the leetcode
	unordered_map<int, int> map;
	int util(int n){
		//check memoised data
    	if(map.find(n) != map.end())
    		return(map[n]);

    	//base cases
	    if(n<=3)
	    {	
	    	map[n] = n;
	    	return n;
	    }

    	int mini = n;
    	for(int k = 1; k*k <= n; k++){
    		
    		int sq = k*k;
    		int rem = n-sq;

    		if(rem == 0)
    		{
    			mini = 1;
    			break;
    		}
    		mini = min(mini, util(rem) +1);
    	}

    	map[n] = mini;
        return mini;
	}
    int numSquaresTD(int n) {

    	int output = util(n);
    	return output;
    }

    //bottom up
    int numSquares(int n){
    	
    	if(n<0) return 0;

    	vector<int> val(n+1, 0);
    	val[0] = 1;

    	for(int i = 1; i<=n; i++){
    		val[i] = i;
    		for(int j = 1; j*j<=i; j++){
    			if( (i-(j*j)) == 0)
    			{
    				val[i] = 1;
    				break;
    			}
    			else
    			{
    				val[i] = min(val[i], 1+ val[i-(j*j)]);
    			}
    			//cout << "i is: " << i << " j is: " << j << " val is: " << val[i] << endl;
    		}
    		
    	}
    	return val[n];
    }
};

int main(){

	int n;
	cin >> n;

	//cout << int(2.9) << endl;
	Solution sol;
	int output = sol.numSquares(n);
	cout << "output is: " << output << endl;
	return 0;
}