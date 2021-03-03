/*
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<cmath>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

    	vector<char> open = {'{', '[', '('};
    	vector<char> state;

    	for(auto it=s.begin(); it!=s.end(); it++)
    	{
    		char curr_s = *it;
    		if(find(open.begin(), open.end(), curr_s) != open.end())
    		{
    			//if we found an open bracket
    			state.push_back(curr_s);
    		}
    		else
    		{
    			if(!state.size())
    			{
    				return false;
    			} 
    			char last_open = state.back();
    			if(curr_s == '}' && last_open != '{') return false;
    			if(curr_s == ']' && last_open != '[') return false;
    			if(curr_s == ')' && last_open != '(') return false;
    			state.pop_back();
    		}

    	}

    	if(state.size()==0) return true;
        return false;
    }
};

int main(){
	string s = "()[]{}}";
	//string s = "([)]";
	Solution sol;
	bool output = sol.isValid(s);
	cout << "output is " << output << endl;
	return 0;
}