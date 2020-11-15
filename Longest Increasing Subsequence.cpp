/*
300. Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

(btw solution here: 
1. https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
2. https://algorithmsandme.com/longest-increasing-subsequence-in-onlogn/
)
*/

#include<vector>
#include<iostream>
#include<cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
	int LCS( vector<int>& a, vector<int>& b )
	{
		int m = a.size();
		int n = b.size();
		if(m<=0 || n <= 0) return 0;

		int dp[m][n];

		//initialize column 1
		for(int i=0; i<m; i++){
			if(i==0)
				dp[i][0] = (a[0]==b[0]) ? 1:0;
			
			else if(a[i] == b[0])
			{
				dp[i][0] = 1;
			}
			else
			{
				dp[i][0] = dp[i-1][0];
			}
		}

		//initialize row 1
		for(int j=0; j<n; j++){
			if(j==0)
				dp[0][j] = (a[0]==b[j]) ? 1:0;
			
			else if(a[0] == b[j])
			{
				dp[0][j] = 1;
			}
			else
			{
				dp[0][j] = dp[0][j-1];
			}
		}

		//start filling the matrix
		for(int i=1; i<m; i++){
			for(int j=1; j<n; j++){
				if(a[i] == b[j])
				{
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		return dp[m-1][n-1];
	}

	//using longest common subsequence problem -> high on storage side! (Accepted)
    int lengthOfLISLCS(vector<int>& nums) {
    	vector<int> nums_sort(nums.size(), 0);
    	//cout << "here " << endl;

    	for(int i=0; i<nums.size(); i++){
    		nums_sort[i] = nums[i];
    	}

    	sort(nums_sort.begin(), nums_sort.end());

    	vector<int>::iterator ip; 
    	ip = unique(nums_sort.begin(), nums_sort.end());
    	nums_sort.resize(std::distance(nums_sort.begin(), ip)); 

    	int output = LCS(nums, nums_sort);
        return output;
    }

    //standard DP solution
    int lengthOfLIS(vector<int>& nums){
    	int n = nums.size();
    	if(n<=0) return 0;
    	int dp[n];

    	//length of LIS
    	int max_LIS = 1;
    	for(int i=0;i<n;i++){
    		
    		//max of LIS ending at i (including i)
    		int max = 0;
    		dp[i] = 1;
    		
    		for(int j=0; j<i;j++){
    			if(nums[i]>nums[j]){
    				int curr_max = dp[j];
    				if(curr_max > max) max = curr_max;
    			}
    			
    		}
    		dp[i] = max + 1;
    		cout << "i is: " << i << " dp is " << dp[i] << endl;
    		if(max_LIS < dp[i]) max_LIS = dp[i];
    	}
    	return max_LIS;
    }

    int binary_search_self(vector<int>& a, int n){
    	int l = 0;
    	int r = a.size()-1;
		
		if(n<a[l]) return -1;
		if(n>a[r]) return r;

    	while(l<r)
    	{

    		int mid = (l+r)/2;

    		if(a[mid] == n) return mid-1;

    		if(l+1 == r) return l;
    		if(a[mid] > n)
    		{
    			r = mid;
    			continue;
    		}
    		if(a[mid]<n)
    		{
    			l = mid;
    			continue;
    		}
    	}

    	return 0;
    }

    //DP solution with elegant approach
    int lengthOfLISAuxi(vector<int>& nums){
    	int n = nums.size();
    	if(n==0) return 0;
    	vector<int> dp;

    	dp.push_back(nums[0]);
    	for(int i=1; i<n; i++){
    		int index = binary_search_self(dp, nums[i]);
    		if(index==dp.size()-1 )
    		{
    			if(nums[i] > dp[index]) dp.push_back(nums[i]);
    		}
    		else
    		{
    			dp[index + 1] = nums[i];
    		}

    		//print dp for reference
    		/*
    		cout << "dp is: ";
    		for(int k = 0; k<dp.size(); k++){
    			cout << dp[k] << " ";
       		}
       		cout << endl;
       		*/
    	}	
    	return dp.size();
    }
};

int main(){
	/*
	int n;
	vector<int> vect;
	while(cin >> n)
	{
		vect.push_back(n);
	}
	*/

	vector<int> vect{10,9,2,5,3,7,101,18};
	//vector<int> vect{2,2};
	Solution sol;
	//int output = sol.lengthOfLISLCS(vect);
	//int output = sol.lengthOfLIS(vect);
	//int output = sol.binary_search_self(vect, 4);
	int output = sol.lengthOfLISAuxi(vect);
	cout << "Output is: " << output << endl;
	return output;
}