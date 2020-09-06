/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    void sortColorsSickJoke(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
    void sortColors2Pass(vector<int>& nums) {
    	int c_0 = 0;
    	int c_1 = 0;
    	for(int i=0; i<nums.size();i++){
    		switch(nums[i]){
    			case 0:
    				c_0++;
    				break;
    			case 1:
    				c_1++;
    				break;
    		};
    	}

    	for(int i=0; i<nums.size();i++){
    		if(i<=c_0-1){
    			nums[i]=0;
    			continue;
    		}
    		if(i<= c_0+c_1-1){
    			nums[i] = 1;
    			continue;
    		}
    		nums[i]=2;
    	}
    }
    void swap(vector<int>& nums, int i, int j)
    {
    	int temp = nums[i];
    	nums[i] = nums[j];
    	nums[j] = temp;
    	return;
    }
    void printVector( vector<int>& nums){
    	for(auto i = nums.begin(); i!=nums.end();i++){
			cout << *i << " ";
		};
		cout << endl;
    }

    //one pass
    void sortColors(vector<int>& nums){
    	int l = 0, mid = 0, h = nums.size()-1;
    	//0....l-1 holds 0, l...mid-1 holds 1,  mid...high unknown, high+1.....nums.size() 2
    	for(int i =mid;i<=h;i++)
    	{
    		switch(nums[i]){
    			case 0:
    				//cout << "Case 0: ";
    				l++;
    				swap(nums, l-1, i);
    				mid++;
    				break;
    			case 1:
    				//cout << "Case 1: ";
    				swap(nums, l, i);
    				mid++;
    				break;
    			case 2:
    				//cout << "Case 2: ";
    				swap(nums, h, i);
    				h--;
    				i--;
    				break;
    		}
    		//cout << nums[i] << " " << i << ": " << l << " " << mid << " " << h << endl;
    		//printVector(nums);	
    	}
    }
};

int main(){

	int input;
	vector<int> num;

	cout << "Please input array"<<endl;
	while(cin >> input) num.push_back(input);

	Solution sol;
	//sol.sortColorsSickJoke(num);
	//sol.sortColors2Pass(num);
	sol.sortColors(num);

	cout << "Solution is " << endl;
    for(auto i = num.begin(); i!=num.end();i++){
		cout << *i << " ";
	};
	cout << endl; 

	return 0;
}