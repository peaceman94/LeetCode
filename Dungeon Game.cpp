/*
174. Dungeon Game

The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N 
rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the 
dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, 
he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; 
other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path 
RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)
 

Note:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned
*/

#include<unordered_map>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:

	//top down solution
	unordered_map<string, int> map;
	int util(vector<vector<int> >& dungeon, int i, int j, unordered_map<string, int> &map){

		//read from map
		string key = to_string(i) + "_" + to_string(j);
		if(map.count(key))
			return(map[key]);

		int m = dungeon.size();
		int n = dungeon[0].size();

		if(i==m-1 && j==n-1){
			int output = (dungeon[i][j] > 0 )?1: (-1*dungeon[i][j]) +1;
			map[key] = output;
			return(map[key]);
		}

		// minimum points needed for the next step
		int minHP;
		if(i == m-1)
			minHP = util(dungeon, i, j+1, map);
		else if(j == n-1)
			minHP = util(dungeon, i+1, j, map);
		else
			minHP = min(util(dungeon, i+1, j, map), util(dungeon, i, j+1, map));

		int output = max(minHP - dungeon[i][j], 1);
		map[key] = output;
		return(output);	
	}

    int calculateMinimumHPTD(vector<vector<int> >& dungeon) {
    	unordered_map<string, int> map;
    	int output = util(dungeon, 0, 0, map);
    	return output;
    }

    //bottom up solution
    int calculateMinimumHPBU(vector<vector<int> >& dungeon) {
    	int n = dungeon[0].size();
    	int m = dungeon.size();

    	vector<int> dp_prev;
    	vector<int> dp;
    	dp.reserve(n); dp_prev.reserve(n);

    	dp[n-1] = (dungeon[m-1][n-1] > 0 )?1: (-1*dungeon[m-1][n-1]) +1;
    	for(int i = n-2; i>=0; i--){
    		dp[i] = max( dp[i+1] - dungeon[m-1][i], 1 );
    	}

    	for(int i = m-1; i>=0; i--){
    		for(int j = n-1; j >=0 ; j--){
    			if(i == m-1 && j == n-1) dp[j] = (dungeon[i][j] > 0 )?1: (-1*dungeon[i][j]) +1;
    			else if( i==m-1)
    			{
    				dp[j] = max( dp[j+1] - dungeon[i][j], 1 );
    			}
    			else if(j==n-1){
    				dp[j] = max( dp_prev[j] - dungeon[i][j], 1 );
    			}
    			else
    			{
    				dp[j] = max( min(dp_prev[j], dp[j+1]) - dungeon[i][j], 1 );
    			}
    		}

    		for(int t = 0; t<n; t++)
    		{
    			dp_prev[t] = dp[t];
    		}

    	}
    	return dp_prev[0];
    }
};

int main(){

	//manual input
	vector<vector<int> > dungeon;
	for(int i = 0; i<3; i++){
		vector<int> vect;
		if(i == 0)
		{
			vect.push_back(-2);
			vect.push_back(-3);
			vect.push_back(3);
		}
		else if(i==1)
		{
			vect.push_back(-5);
			vect.push_back(-10);
			vect.push_back(1);

		}
		else
		{
			vect.push_back(10);
			vect.push_back(30);
			vect.push_back(-5);

		}
		dungeon.push_back(vect);
	}
	
	//
	Solution sol;
	//int output = sol.calculateMinimumHPTD(dungeon);
	int output = sol.calculateMinimumHPBU(dungeon);
	cout << "Output is: " << output << endl;
	return 0;
}