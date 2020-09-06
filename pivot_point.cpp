/*
724. Find Pivot Index
Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of all the numbers to the left of the index is equal to the sum of all the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
 

Constraints:

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].
*/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
	void printVector( vector<int>& nums){
    	for(auto i = nums.begin(); i!=nums.end();i++){
			cout << *i << " ";
		};
		cout << endl;
    }
    int pivotIndexNaive(vector<int>& nums) {
    	if(nums.size() == 0) return -1;
    	vector<int> sum_i;
    	sum_i.reserve(nums.size());

    	sum_i.push_back(nums[0]);
    	for(int i = 1; i< nums.size(); i++){
    		sum_i[i] = sum_i[i-1] + nums[i];
    	}
    	//printVector(sum_i);
    	for(int i=0; i<nums.size(); i++){
    		if((sum_i[i] - nums[i]) == (sum_i[nums.size()-1] - sum_i[i]))
    			return i;
    	}
        return -1;
    }

    int pivotIndex(vector<int>& nums) {
    	int sum = accumulate(nums.begin(), nums.end(), 0);
    	int left_sum = 0;
    	int size = nums.size();
    	for(int i=0;i<size;left_sum += nums[i++]){
    		if((left_sum) == (sum - left_sum - nums[i]))
    			return i;
    	}

    	return -1;
    }
};

int main(){

	int input;
	vector<int> nums;

	cout << "Please input array"<<endl;
	while(cin >> input) nums.push_back(input);
	
	Solution sol;
	//int pivot = sol.pivotIndexNaive(nums);
	int pivot = sol.pivotIndex(nums);

	cout << "pivot is " << endl;
	cout << pivot << endl;
	return 0;
}
