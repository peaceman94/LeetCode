/*
93. Restore IP Addresses
Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.

A valid IP address consists of exactly four integers, each integer is between 0 and 255, 
separated by single dots and cannot have leading zeros. 
For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and 
"0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 

 

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "1111"
Output: ["1.1.1.1"]
Example 4:

Input: s = "010010"
Output: ["0.10.0.10","0.100.1.0"]
Example 5:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

Constraints:

0 <= s.length <= 3000
s consists of digits only.
*/

#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

class Solution {
public:
	vector<string> output = {};
	void helper(string s, int n, int start, int count_dots, string curr_sol)
	{
		//cout << start << ", " << count_dots << ", " <<  curr_sol << endl;
		//exit condition
		if(count_dots != 0 && start >= n) return;
		if(count_dots == 0 )
		{
			if(start == n) output.push_back(curr_sol);
			return;
		};

		for(int i=start; i<=min(start+2, n);i++)
		{
			//if single letter digit and is 0 then fine, else if multiple letter digit and begin with 0 continue;
			if(i!=start && s[start] == '0') continue;
			int curr_address_int = stoi(s.substr(start, i-start+1));
			if(curr_address_int >255) continue;

			//so far it looks like the valid digit of curr address
			string arg;
			if(curr_sol.size()) 
			{
				arg = curr_sol + "." + to_string(curr_address_int);
				helper(s, n, i+1, count_dots - 1, arg);
			}
			else
			{
				arg = curr_sol + to_string(curr_address_int);
				helper(s, n, i+1, count_dots, arg);
			}
				
			
		}
		return;
	}
    
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        helper(s,n, 0, 3, "");
        return output;
    }
};

int main()
{
	string s = "25525511135";
	Solution sol;
	auto output = sol.restoreIpAddresses(s);
	for(auto x:output)
		cout << x << ", " << endl;;
	cout << endl;
	return 0;
}


