/*
12. Integer to Roman

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Example 2:

Input: num = 4
Output: "IV"
Example 3:

Input: num = 9
Output: "IX"
Example 4:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999

*/

#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;



class Solution {
public:
	map<int, string> rx = 
	{
		{1,  	"I" },
		{4,  	"IV"},
		{5,  	"V" },
		{9, 	"IX"},
		{10, 	"X" },
		{40, 	"XL"},
		{50, 	"L" },
		{90, 	"XC"},
		{100, 	"C" },
		{400, 	"CD"},
		{500, 	"D" },
		{900, 	"CM"},
		{1000, 	"M" }	
	};

    string intToRomanNaive(int num) {
    	//cout << "number is: " << num << endl;
    	string output = "";
    	if(num <= 0) return output;

    	for(auto it = rx.rbegin(); it != rx.rend(); it++)
    	{
    		int curr_ind = it->first;
    		if(curr_ind <= num)
    		{
    			output += (it->second);
    			output += intToRomanNaive(num - curr_ind);
    			break;
    		}
    	}

    	return output;
    }

   string intToRomanNaive2(int num) {
    	//cout << "number is: " << num << endl;
    	string output = "";
    	if(num <= 0) return output;

    	for(auto it = rx.rbegin(); it != rx.rend(); it++)
    	{
    		int curr_ind = it->first;
    		if(curr_ind <= num)
    		{
    			int div = num/curr_ind;
    			int next_num = num%curr_ind;
    			while(div)
    			{
    				output += it->second;
    				div--;
    			}
    			output += intToRomanNaive2(next_num);
    			break;
    		}
    	}

    	return output;
    }   

   string intToRoman(int num) {
    	//cout << "number is: " << num << endl;
    	string output = "";
    	auto it = rx.rbegin();
    	while(num > 0)
    	{
    		int curr_ind = it->first;
    		if(curr_ind <= num)
    		{
    			int div = num/curr_ind;
    			num = num%curr_ind;
    			while(div)
    			{
    				output += it->second;
    				div--;
    			}
    		}
    		if(it == rx.rend()) break;
    		it++;
    	}
    	return output;
    }       
};

int main()
{
	int n;
	cout << "Enter a number for Roman" << endl;
	cin >> n;

	Solution sol;
	string output = sol.intToRoman(n);
	cout << "output is: " << output << endl;

}
