/*
132. Palindrome Partitioning II

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1

*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
	unordered_map<string, int> map;
	unordered_map<string, int> pmap;
	bool isPalindrome(string s, int i, int j){
		string key = to_string(i) + "_" + to_string(j);
		if(pmap.count(key))
			return(pmap[key]);

		bool output = true;
		while( i < j ){
			if(s[i] == s[j]){
				i++;
				j--;
			}
			else{ output = false; break; }
		}
		pmap[key] = output;
		return output;	
	}

	int util(string s, int i, int j){

		//Try to read from cache first
		string key = to_string(i) + "_" + to_string(j);
		if(map.count(key))
			return(map[key]);

		if(i==j) return 0;
		if(isPalindrome(s,i,j)) return 0;

		int min = INT_MAX;
		for(int k = i; k < j; k++){

			//handle the left key
			int left_min = INT_MAX;
			string left_key = to_string(i) + "_" + to_string(k);
			if(map.count(left_key))
				left_min = map[left_key];
			if(left_min == INT_MAX)
			{
				left_min = util(s, i, k);
				map[left_key] = left_min;
			}

			//handle the right key
			int right_min = INT_MAX;
			string right_key = to_string(k+1) + "_" + to_string(j);
			if(map.count(right_key))
				right_min = map[right_key];
			if(right_min == INT_MAX)
			{
				right_min = util(s, k+1, j);
				map[right_key] = right_min;
			}

			int curr_output = left_min + 1 + right_min;
			if(curr_output < min) min = curr_output;
		}
		
		map[key] = min;
		return min;
	}

	//doesnt pass the time in leetcode -> need to revist
    int minCut(string s) {
    	int output = util(s, 0, s.size()-1);
        return output;
    }
};

int main(){
	string s;
	cin >> s;

	Solution sol;
	int output = sol.minCut(s);
	//int output = sol.isPalindrome(s, 0, s.size()-1);
	cout << "output is " << output << endl;
	return output;
}