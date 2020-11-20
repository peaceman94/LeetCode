/*
9. Palindrome Number

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Follow up: Could you solve it without converting the integer to a string?

 

Example 1:

Input: x = 121
Output: true
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Example 4:

Input: x = -101
Output: false
 

Constraints:

-231 <= x <= 231 - 1
*/

#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	//without converting to string
    bool isPalindromeNonString(int x) {

    	if(x < 0) return false;
    	vector<int> num;
    	while(x !=0){
    		num.push_back( x%10 );
    		x = x/10;
    	}
    	for(int i=0; i< num.size()/2; i++){
    		if(num[i] != num[num.size()-1-i])
    			return false;
    	}
 		return true;
    }

    //using string
    bool isPalindrome(int x) {
    	if(x<0)return false;
    	string s = to_string(x);
    	string t = s;
    	reverse(s.begin(), s.end()); 
    	return s == t;
    }	
};

int main(){
	int x = 1234543213;
	Solution sol;
	int output = sol.isPalindromeNonString(x);
	cout << "output is "<< output << endl;
	return 0;
}