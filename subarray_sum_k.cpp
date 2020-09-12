/*
560. Subarray Sum Equals K

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
 

Constraints:

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

*/

#include<iostream>
#include<vector>
#include<numeric>
#include <unordered_map> 
using namespace std;

class Solution {
public:
	//foreach subarray find the sum and see if it is equal to k. O(n^2).
	int subarraySumBruteForce(vector<int>& nums, int k) {
		int output = 0;
    	for(int s=0; s<nums.size(); s++){
    		int curr_s_sum = 0;
    		for(int e=s; e<nums.size(); e++){
    			//Sum of numbers from s to e
    			curr_s_sum += nums[e];
    			if(curr_s_sum == k) output++;
    		}
    	}
        return output;
    }
    int subarraySum(vector<int>& nums, int k) {
    	unordered_map<int,int> sum;
    	int sum_d = 0;
    	int output = 0;
    	
    	sum.insert(make_pair(0,1));
    	
    	for(int i=0; i< nums.size();i++){
    		sum_d += nums[i];
    		if(sum.count(sum_d-k)){
    			output += sum[sum_d-k];
    		}
    		sum[sum_d] += 1;
    	}
    	return output;
    }
};

int main(){

	int k;
	int input;
	vector<int> nums;

	cout << "please input the target sum " << endl;
	cin >> k;
	cout << "Please input array"<<endl;
	while(cin >> input) nums.push_back(input);
	
	Solution sol;
	//int sum = sol.subarraySumBruteForce(nums, k);
	
	int sum = sol.subarraySum(nums, k);

	cout << "sol is " << endl;
	cout << sum << endl;
	return 0;
}
