/*
17. Letter Combinations of a Phone Number


Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*/

#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
	unordered_map<string, vector<string>> map = 
	{
		{ "2", {"a", "b", "c"} },
		{ "3", {"d", "e", "f"} },
		{ "4", {"g", "h", "i"} },
		{ "5", {"j", "k", "l"} },
		{ "6", {"m", "n", "o"} },
		{ "7", {"p", "q", "r", "s"} },
		{ "8", {"t", "u", "v"} },
		{ "9", {"w", "x", "y", "z"} }
	};

	vector<string> cross_tab(string s, vector<string>& input)
	{
		vector<string> output = {};
		if(input.size() == 0)
		{
			output.push_back(s);
			return output;
		};

		for(int i=0; i<input.size(); i++)
		{
			output.push_back(s + input[i]);
		}
		return output;
	};

    vector<string> letterCombinations(string digits) 
    {
        vector<string> output = {  };

        //if zero length, return empty output
        if(digits.size() == 0) return output;

        //extract the first digit and process the rest
        string curr_dig(1, digits[0]);
       	vector<string> sub_output = letterCombinations( digits.substr(1));

        vector<string> words = map[curr_dig];
    	for(int i = 0; i<words.size(); i++ )
    	{
       		vector<string> temp = cross_tab(words[i], sub_output);
       		output.insert(output.end(), temp.begin(), temp.end());
    	}
        return output;
    }
};

int main()
{
	string s = "4";
	Solution sol;
	vector<string> output = sol.letterCombinations(s);
	
	cout << "output is: " << endl;
	for(int i=0; i<output.size(); i++)
	{
		cout << output[i] << "\n";
	}
	cout << endl;

}