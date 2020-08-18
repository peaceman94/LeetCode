#include<iostream>
using std::string;
using namespace std;

class Solution {
public:
	bool isPalindrome(string s){
		
		int i = 0;
		int j = s.length()-1;

		while(j>=i)
		{
			if(s[i] != s[j])
				return( false );
			i++;
			j--;
		}
		return true;
	};
	
    string longestPalindromeNaive(string s) {
    	string lon_palin;
    	int max_len = 0;

    	for(int i = 0; i<s.length(); i++)
    		for(int j = i; j < s.length(); j++)
    		{
    			string curr_str = s.substr(i, j-i+1);
    			if(isPalindrome(curr_str))
    			{
    				if(curr_str.length() > max_len)
    				{
    					max_len = curr_str.length();
    					lon_palin = curr_str;
    				}
    			}
    		}
    	string output = (max_len>0)?lon_palin:"";
    	return(output);
    };
};

int main()
{
	//take input
	string s;
	cout << "Please enter the string: " << endl;
	std::cin >> s;
	
	Solution sol;
	string lon_palin = sol.longestPalindromeNaive(s);
	std::cout << lon_palin << std::endl;
	return 0;
}