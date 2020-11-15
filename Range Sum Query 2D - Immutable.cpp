/*
304. Range Sum Query 2D - Immutable

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:

Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:

You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class NumMatrix {
private: 
	vector<vector<int> > sum_m;
	vector<vector<int> > matrix;
	int m;
	int n;
public:
    NumMatrix(vector<vector<int>>& input) {
        m = input.size();
    	n = (m>0)? input[0].size():0;

    	//initialize and store the matrix
    	matrix = vector<vector<int> >(m, vector<int>(n,0));
    	for(int i=0; i<m; i++){
    		for(int j=0; j<n; j++){
    			matrix[i][j] = input[i][j];
    		}
    	}
    	
    	if(m==0 || n==0) return;

    	//initialize sum_m;
    	sum_m = vector<vector<int> >(m, vector<int>(n,0));
    	sum_m[0][0] = input[0][0];
    	for(int i = 1; i<n; i++){
    		sum_m[0][i] = sum_m[0][i-1] + input[0][i];
    	}
    	for(int i = 1; i<m; i++){
    		sum_m[i][0] = sum_m[i-1][0] + input[i][0];
    	}
    	for(int i=1; i<m; i++){
    		for(int j=1; j<n; j++){
    			sum_m[i][j] = sum_m[i-1][j] + sum_m[i][j-1] - sum_m[i-1][j-1] + input[i][j];
    		}
    	}

    }
    //vector<vector<int> > memo = initializeSum();
    int sumRegion(int row1, int col1, int row2, int col2) {

    	if(m==0||n==0) return 0; 
    	   	
    	int output = sum_m[row2][col2] - sum_m[row1][col1] + matrix[row1][col1];
    	if(col1-1 >=0 )
    		output -= sum_m[row2][col1-1] - sum_m[row1][col1-1];
    	if(row1-1>=0)
    		output -= sum_m[row1-1][col2] - sum_m[row1-1][col1];

    	//printVec(matrix);
    	return output;
    }

    void printVec(vector<vector<int>>& input){
        m = input.size();
    	n = (m>0)? input[0].size():0;
		
    	for(int i=0; i<m; i++){
    		for(int j=0; j<n; j++){
    			cout << input[i][j] << "\t";
    		}
    		cout << endl;
    	}
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

 int main(){

	/*
 	vector<vector<int>> matrix{
	{3,0,1,4,2},
	{5,6,3,2,1},
	{1,2,0,1,5},
	{4,1,0,1,7},
	{1,0,3,0,5},
	};
	*/

	vector<vector<int>> matrix{{-1}};
 	NumMatrix sol(matrix);
 	int r1 = 0, c1 = 0, r2 = 0, c2 = 0;

 	int output = sol.sumRegion(r1,c1,r2,c2);
 	cout << "output is: " << output << endl;

 	//sol.printVec();
 	return 0;
 }