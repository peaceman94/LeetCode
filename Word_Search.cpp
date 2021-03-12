/*
79. Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Note: There will be some test cases with a board or a word larger than constraints to test if your solution is using pruning.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
*/

#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

class Solution {
public:

	//I am not proud of this solution but this is acceptred
	bool helper(vector<vector<char>>& board, string& word, int m, int n, int i, int j, vector<vector<int>>& visited, string& curr_word )
	{
		cout << curr_word << " " << i << " " << j << endl;
		//boundary conditions
		if(curr_word == word)
		{
			return true;
		};

		if(i == m || j == n)
		{
			return false;
		};

		//from the current node explore all the neigboring nodes if not visited already and update the 
		//things to be passed ont the helper function
		//1. (i-1, j)
		bool output = false;
		int curr_word_size = curr_word.size();
		if(i-1 >= 0 && visited[i-1][j] == 0 && (board[i-1][j] == word[curr_word_size]) )
		{
			visited[i-1][j] = 1;
			curr_word = curr_word + board[i-1][j];
			
			output = output || helper(board, word, m, n, i-1, j, visited, curr_word);
			
			curr_word.pop_back();
			visited[i-1][j] = 0;

			if(output == true) return output;
		}

		//2. (i+1, j)
		if(i+1<m && visited[i+1][j] == 0 && (board[i+1][j] == word[curr_word_size]))
		{
			visited[i+1][j] = 1;
			curr_word = curr_word + board[i+1][j];
			
			output = output || helper(board, word, m, n, i+1, j, visited, curr_word);
			
			curr_word.pop_back();
			visited[i+1][j] = 0;

			if(output == true) return output;
		}

		//3. (i, j-1)
		if( j-1 >=0 && visited[i][j-1] == 0 && (board[i][j-1] == word[curr_word_size]))
		{
			visited[i][j-1] = 1;
			curr_word = curr_word + board[i][j-1];

			output = output || helper(board, word, m, n, i, j-1, visited, curr_word);
			
			curr_word.pop_back();
			visited[i][j-1] = 0;	

			if(output == true) return output;		
		}

		//4. (i, j+1)
		if( j+1 <n && visited[i][j+1] == 0 && (board[i][j+1] == word[curr_word_size]))
		{
			visited[i][j+1] = 1;
			curr_word = curr_word + board[i][j+1];

			output = output || helper(board, word, m, n, i, j+1, visited, curr_word);
			
			curr_word.pop_back();
			visited[i][j+1] = 0;	

			if(output == true) return output;		
		}

		return output;
	};

    bool exist(vector<vector<char>>& board, string word){

    	int m = board.size();
    	if(m == 0) return false;
    	int n = board[0].size();

    	vector<vector<int >> visited(m, vector<int>(n));
    	
    	bool output = false;
    	for(int i = 0; i<m; i++)
    	{
    		for(int j=0; j<n; j++)
    		{
    			if(board[i][j] != word[0]) continue;

    			visited[i][j] = 1;
    			string curr_word(1, board[i][j]);
    			//check if the first word of the word to be matched is inline with curr_word
    			//if(curr_word != word.substr(0,1)) continue;
    			output = output || helper(board, word, m, n, i, j, visited, curr_word);

    			visited[i][j] = 0;
    			if(output == true) break;
    		}
    	}
        return output;
    }
};

void print_vector(vector<vector<int>> input)
{
	for(int i = 0; i<input.size(); i++)
	{
		for(int j = 0; j<input[i].size(); j++ )
		{
			cout << input[i][j] << " ";
		}
		cout << endl;
	}
}; 

int main()
{
	//vector<vector<char>> board  = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//string word = "ABCCED";

	//vector<vector<char>> board  = {{'A','B'}};
	//string word = "BA";

	vector<vector<char>> board = {{'b','b','a','a','b','a'},{'b','b','a','b','a','a'},
	{'b','b','b','b','b','b'},{'a','a','a','b','a','a'},{'a','b','a','a','b','b'}};
	string word = "abbbababaa";
	

	Solution sol;
	bool output = sol.exist(board, word);
	cout << "output is " << output << endl;
	//print_vector(output);
};