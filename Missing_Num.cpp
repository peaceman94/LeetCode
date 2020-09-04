
/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
*/
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int sum = int(nums.size() * (nums.size() + 1) * 0.5 );
    	int num_sum = accumulate(nums.begin(), nums.end(), 0);
    	int missing = int(sum - num_sum);
        return missing;
    }
};

int main(){

	int input;
	vector<int> num;

	cout << "Please input array"<<endl;
	while(cin >> input) num.push_back(input);
	
	cout << "you have entered the following array via different iterator"<<endl;
	for(auto i = num.begin(); i!=num.end();i++){
		cout << *i << " ";
	};
	cout << endl;

	Solution sol;
	int missingNum = sol.missingNumber(num);
	cout << "missing number is "<<missingNum << endl;
	return 0;
}

