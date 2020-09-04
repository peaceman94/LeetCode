/*
53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int maxSubArrayNaive(vector<int>& num) {
    	int output = num[0];

    	for(int i =0 ; i < num.size(); i++)
    	{
    		for(int j =i;j<num.size();j++)
    		{
    			int curr_sm = accumulate(num.begin()+i, num.begin()+ j + 1, 0);
    			if(curr_sm > output)
    			{
    				output = curr_sm;
    			}
    		}
    	}
        return output;
    };

    int maxSubArray(vector<int>& num) {
			vector<int>curr_streak;
			curr_streak.push_back(num[0]);
			int global_max = num[0];

			for(int i=1; i<num.size(); i++)
			{
				curr_streak.push_back( max(curr_streak[i-1] + num[i], num[i] ) );
				if(global_max < curr_streak[i])
					global_max = curr_streak[i];

			}
    		return(global_max);
    }
}; 

int main()
{
	int len;
	cout << "please enter the length of array" << endl;
	cin >> len;
	
	vector<int> num;
	num.reserve(len);

	cout << "enter the array now" << endl;
	int inp;

	for(int i=0;i<len;i++)
	{
		cin >> inp;
		num.push_back(inp);
	};
	
	cout << "the array you have entered is :" << endl;
	for(auto i = num.begin(); i!=num.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
	cout << "calling the Daddy now . . ." << endl;

	Solution sol;
	//int sum = sol.maxSubArrayNaive(num);
	int sum = sol.maxSubArray(num);

	cout << "The max sum is " << sum << endl;
	return 0;

}