/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:

	//not super proud of below func.
	void nextPermutation(vector<int>& nums){
		if(nums.size() == 1) return;

		int pivot = -1;
		for(int i = nums.size()-2; i>=0; i--){
			if( nums[i] < nums[i+1])
			{
				pivot = i;
				break;
			}
		}
		
		if(pivot != -1)
		{
			int sec_max_ind = nums.size()-1;
			while(sec_max_ind>=0 && nums[sec_max_ind]<=nums[pivot])
				sec_max_ind--;

			//swap num[pivot] and nums[sec_max_ind]
			int temp = nums[pivot];
			nums[pivot] = nums[sec_max_ind];
			nums[sec_max_ind] = temp;
			cout << "second max index is " << sec_max_ind << endl;
		}
		

		//reverese array from pivot+1 to end
		int l = pivot+1;
		int r = nums.size()-1;
		while( l < r)
		{
			if(nums[l] > nums[r])
			{
				int temp = nums[l];
				nums[l] = nums[r];
				nums[r] = temp;

			}
				
			l++;
			r--;
		}
		return;
	}

	//works fine - faster and space efficient than 97% at the time sep6, 20  --> accepted in Leetcode as well
    void nextPermutationNaive(vector<int>& nums) {
		if(nums.size() == 1)
			return;

		if( nums.back() > nums[nums.size()-2]){
			int temp = nums.back();
			nums.back() = nums[nums.size()-2];
			nums[nums.size()-2] = temp;
			return;
		}

		//find the index of an element such that array from 0 .... index doesnt need to change
		int max = nums[nums.size()-1];
		int index = nums.size()-2;
		for(auto i = nums.rbegin() + 1; i!= nums.rend(); i++)
		{
			if(*i < max)
				break;

			max = *i;
			index --;
		}

		//entire array needs to be sorted
		if(index == -1)
		{
			sort(nums.begin(), nums.end());
			return;
		}
		
		//find index of an element just larger than nums[index]
		int dist = nums[index + 1] - nums[index];
		int sec_max_ind = index + 1;
		for(int i = index+2; i < nums.size(); i++){
			int temp = nums[i] - nums[index];
			if(dist > temp && nums[i] > nums[index])
			{
				dist = temp;
				sec_max_ind = i;	
			}
		}

		//swap sec_max_ind with index.
		int temp = nums[index];
		nums[index] = nums[sec_max_ind];
		nums[sec_max_ind] = temp;

		//sort array from index+1 onwards
		sort(nums.begin()+ index + 1, nums.end());
		return;
    }
};

int main(){

	int input;
	vector<int> num;

	cout << "Please input array"<<endl;
	while(cin >> input) num.push_back(input);
	
	/*
	cout << "you have entered the following array:"<<endl;
	for(auto i = num.begin(); i!=num.end();i++){
		cout << *i << " ";
	};
	cout << endl;
	*/

	Solution sol;
	//sol.nextPermutationNaive(num);
	sol.nextPermutation(num);

	cout << "Next permutation is " << endl;
    for(auto i = num.begin(); i!=num.end();i++){
		cout << *i << " ";
	};
	cout << endl; 

	return 0;
}