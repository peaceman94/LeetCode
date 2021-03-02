/*
Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:
Input: board = 
{{"5","3",".",".","7",".",".",".","."}
,{"6",".",".","1","9","5",".",".","."}
,{".","9","8",".",".",".",".","6","."}
,{"8",".",".",".","6",".",".",".","3"}
,{"4",".",".","8",".","3",".",".","1"}
,{"7",".",".",".","2",".",".",".","6"}
,{".","6",".",".",".",".","2","8","."}
,{".",".",".","4","1","9",".",".","5"}
,{".",".",".",".","8",".",".","7","9"}}
Output: true
Example 2:

Input: board = 
{{"8","3",".",".","7",".",".",".","."}
,{"6",".",".","1","9","5",".",".","."}
,{".","9","8",".",".",".",".","6","."}
,{"8",".",".",".","6",".",".",".","3"}
,{"4",".",".","8",".","3",".",".","1"}
,{"7",".",".",".","2",".",".",".","6"}
,{".","6",".",".",".",".","2","8","."}
,{".",".",".","4","1","9",".",".","5"}
,{".",".",".",".","8",".",".","7","9"}}
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<string>>& board) {
        
        return true;    
    }
    bool isValidSudokuBrute(vector<vector<string>>& board) {
        int n = board.size();
        if(n==0) return true;

        int m = board[0].size();
        cout << m << " " << n << endl;
        
        //foreach row check if that row is valid
        for(int i = 0; i<n; i++)
        {
            unordered_map<string,int> map;
            for(int j = 0 ; j<m; j++)
            {
                if(board[i][j] == ".") continue;
                //check if the entry exists already
                if(map.find(board[i][j]) == map.end())
                {
                    map[board[i][j]] = 1;
                }
                else
                {
                    //cout << "row box is error" << endl;
                    return false;
                };
            }
        }

        //foreach column check if it is a valid column
        for(int j = 0 ; j<m; j++)
        {
            unordered_map<string,int> map;
            for(int i = 0; i<n; i++)
            {
                if(board[i][j] == ".") continue;
                //check if the entry exists already
                if(map.find(board[i][j]) == map.end())
                {
                    map[board[i][j]] = 1;
                }
                else
                {
                    //cout << "column box is error: " << board[i][j] << " is present more than once in "<< j<< endl;
                    return false;
                };
            }
        }

        //find if each small square is valid or not
        for(int start_i=0; start_i<n; start_i+= 3)
        {
            int end_i = start_i + 3;
            for(int start_j=0; start_j<n; start_j+= 3)
            {
                int end_j = start_j + 3;

                unordered_map<string,int> map;
                for(int i = start_i; i<end_i; i++)
                {
                    for(int j = start_j ; j<end_j; j++)
                    {
                        if(map.find(board[i][j]) == map.end())
                        {
                            map[board[i][j]] = 1;
                        }
                        else
                        {
                            //cout << "3X3 box is error" << endl;
                            return false;
                        };
                    }
                }
            }

        }

        return true;    
    }
};

int main(){
    vector<vector<string>> board
        {
            {"8","3",".",".","7",".",".",".","."},
            {"6",".",".","1","9","5",".",".","."}, 
            {".","9","8",".",".",".",".","6","."}, 
            {"8",".",".",".","6",".",".",".","3"},
            {"4",".",".","8",".","3",".",".","1"},
            {"7",".",".",".","2",".",".",".","6"},
            {".","6",".",".",".",".","2","8","."},
            {".",".",".","4","1","9",".",".","5"},
            {".",".",".",".","8",".",".","7","9"}
        };
    Solution sol;
    bool output = sol.isValidSudokuBrute(board);
    cout << "out is " << output << endl;
    return 0;
}