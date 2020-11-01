/*
120. Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

#include<vector>
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
	//top down approach
	unordered_map<string, int> map;
	int util(vector<vector<int> > &t, int r, int ind){

		string key = to_string(r) + '_' + to_string(ind);
		if(map.count(key)){
			return(map[key]);
		}
		int output = t[r][ind];
		//check if the row rexists in the triangle
		int sz = t.size();
		if(r == sz-1){
			return output;
		}
		else
		{
			output += min( util(t, r+1, ind), util(t, r+1, ind +1) );
		}
		map[key] = output;
		return output;
	}
    int minimumTotalMemo(vector<vector<int> >& triangle) {

    	int output = util(triangle, 0, 0);
		return output;        
    }
    //bottom up approach
    int utilBU( vector<vector<int> > &t){
    	int rows = t.size()-1;

    	if(rows < 0) return 0;

    	vector<vector<int> > dp;
    	//initialize vector
    	for(int i = rows; i>=0; i--){
    		vector<int> temp;
    		for(int j = 0; j<= rows; j++){
    			temp.push_back(0);
    		}
    		dp.push_back(temp);
    	}
    	for(int i = rows; i>=0; i--){
    		for(int j = 0; j<= i; j++){
    			if(i == rows){
    				dp[i][j] = t[i][j];
    				//cout << i << " " << j << " " << t[i][j] << endl;
    			}
    			else{
    				dp[i][j] = min(t[i][j] + dp[i+1][j], t[i][j] + dp[i+1][j+1] );
    			}

    		}
    	}
    	return(dp[0][0]);
    }
    //with onlu o(N) storage!
    int utilBU2( vector<vector<int> > &t){
    	int rows = t.size()-1;

    	if(rows < 0) return 0;
    	vector<int> dp;
    	vector<int> dp_prev;

    	for(int i = rows; i>=0; i--){
    		for(int j = 0; j<= i; j++){
    			if(i == rows){
    				dp.push_back(t[i][j]);
    				//cout << i << " " << j << " " << t[i][j] << endl;
    			}
    			else{
    				dp[j] = min( dp_prev[j], dp_prev[j+1] ) + t[i][j];
    			}

    		}
    		dp_prev = dp;
    	}

    	return(dp[0]);
    }
    int minimumTotal( vector<vector<int> >& triangle ){
    	int output = utilBU2(triangle);
    	return output;
    }
};

int main(){
	
	//int T_H;
	//cout << "enter the hieght of triangle" << endl;
	//cin >> T_H;


	vector<vector<int> > T { {2}, {3,4}, {6,5,7}, {4,1,8,3} };	

	// for(int i=0; i<T_H; i++){
	// 	vector<int> row;
	// 	int input;
	// 	cout << "Please input array"<<endl;
	// 	while(cin >> input) row.push_back(input);
	// 	T.push_back(row);
	// }

	Solution sol;
	int output = sol.minimumTotal( T );
	cout << "Output: "<< output << endl;
	return 0;
}