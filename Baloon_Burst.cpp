/*
Baloon Burst
*/

#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
	map<vector<int>, int> map;
	int utilNaive(vector<int> nums){

		if(map.find(nums) != map.end()){
			return map[nums];
		}
		int n = nums.size();

		if(n<=0) return 0;
		if(n==1) return nums[0];
		if(n==2)
		{
			int output = (nums[0] * nums[1]) + max( nums[0], nums[1]);
			map[nums] = output;
			return output;
		}

		int max = INT_MIN;
		for(int i=0; i<n; i++){
			int product;
			if(i==0)
			{
				product = 1 * nums[i] * nums[i+1];

			}
			else if(i==n-1)
			{
				product = 1 * nums[i] * nums[i-1];
			}
			else
			{
				product = nums[i-1] * nums[i] * nums[i+1];
			}

			vector<int> left = vector<int>(nums.begin(), nums.begin() + i);
			vector<int> right = vector<int>(nums.begin() + i+1, nums.end());
			left.insert( left.end(), right.begin(), right.end() );

			int curr = product + utilNaive(left);
			if(curr > max) max = curr;
		}

		map[nums] = max;
		return max;
	}

	//try bursting each ballon  and find the max using recursion and memoisation
    int maxCoinsNaive(vector<int>& nums) {
    	int output = utilNaive(nums);
        return output;
    }

    unordered_map<string, int> memo;
    //divide and conquer + dynamic programming memoisation
    int utilTopDown(vector<int> nums, int l, int r){
    	if(r < l) return 0;

    	string key = to_string(l) + "_" + to_string(r); 
    	if(memo.count(key)){
    		return memo[key];		
    	}

    	//iterate over each baloon assuming its the last and evaluate left and right
    	int max = INT_MIN;
    	for(int i =l; i<=r; i++){
    		int product;

    		if(l-1 >=0 && r+1 <= nums.size()-1)
    			product = nums[l-1] * nums[i] * nums[r + 1];
    		else if(l-1<0 && r+1 <= nums.size()-1)
    			product = 1 * nums[i] * nums[r + 1];
    		else if(l-1 >=0 && r+1 > nums.size()-1)
    			product = nums[l-1] * nums[i] * 1;
    		else
    			product = nums[i];

    		int score =  utilTopDown(nums, l, i-1) + product + utilTopDown(nums, i+1, r);
    		max = (score>max) ?score:max;
    	}

    	memo[key] = max;
    	return max;
    }

    int maxCoinsTopDown(vector<int> nums){
    	int output = utilTopDown(nums, 0, nums.size()-1); 
    	return output;
    }
    
    //Actual solution
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), {1});
        nums.push_back(1);

        vector<vector<int> > dp(n+2, vector<int>(n+2, 0) );
        for(int l = 1; l <= n; l++){
            //cout << "l is : " << l << endl;
            for(int i = 1; i<n-l+2; i++){
                int j = i + l - 1;
                //cout << "i, j: " << i << " " << j << endl;
                for(int k = i; k<=j; k++){
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1]);
                }
            }
        }
        return dp[1][n];
    }
};     


int main(){
    
    vector<int> nums{3,1,5,8};
    Solution sol;
    int output = sol.maxCoins(nums);
    cout << "output is " << output << endl;
    return 0;
}
