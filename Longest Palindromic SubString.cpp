#include<iostream>
using std::string;
using namespace std;

class Solution {
public:
	bool isPalindrome(string s){
		
		//std::cout << "current substing is " << s << std::endl;
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
    			//std::cout << i << " " << j << endl;
    			string curr_str = s.substr(i, j-i+1);
    			//std::cout << "current substing is " << curr_str << std::endl;
    			if(isPalindrome(curr_str))
    			{
    				if(curr_str.length() > max_len)
    				{
    					max_len = curr_str.length();
    					lon_palin = curr_str;
    				}
    			}
    		}
    	//cout << "max lenght: " << max_len << endl;
    	//cout << "longest palindrome: " << lon_palin << endl;
    	string output = (max_len>0)?lon_palin:"";
    	return(output);
    };
    string longestPalindrome(string s)
    {

    };
};

int main()
{
	//take input
	string s;
	std::cin >> s;
	
	Solution sol;

	string lon_palin = sol.longestPalindromeNaive(s);
	std::cout << lon_palin << std::endl;
	return 0;
}