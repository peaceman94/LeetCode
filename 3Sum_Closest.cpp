/*
16. 3Sum Closest

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

#include<vector>
#include<iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int threeSumClosestNaive(vector<int>& nums, int target) {
        int output=0;
        int max_diff = INT_MAX;

        //sorry for such naiveness, but its accepted in leetcode ! :P
        for(int i = 0; i< nums.size(); i++)
        {
            for(int j = i+1; j<nums.size(); j++ )
            {
                for(int k = j+1; k < nums.size(); k++)
                {
                    int curr_sum = nums[i] + nums[j] + nums[k];
                    int curr_diff = abs(target - curr_sum);

                    if(curr_diff < max_diff)
                    {
                        max_diff = curr_diff;
                        output = curr_sum;
                    }
                }
            }
        }
        return output;
    }

    int threeSumClosest(vector<int>& nums, int target){
        int min_diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-2; i++)
        {

            //cout << "i is: " << i << endl;
            int j = i+1, k = nums.size()-1;
            while(j<k)
            {
                int curr_sum = nums[i] + nums[j] + nums[k];
                int curr_diff = (curr_sum - target);

                if(abs(curr_diff) < abs(min_diff))
                {
                    min_diff = (curr_diff);
                    if(curr_diff == 0)
                        return curr_sum;
                }
                if(curr_diff < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }

        }
        return min_diff + target ;
    }

};



int main()
{
	vector<int> nums{-1,2,1,-4};
    //vector<int> nums{-3, 0, 1, 2};
	int target = 1;
    //int target = 2;
	Solution sol;
	int output = sol.threeSumClosest(nums, target);
	cout << "output is: " << output << endl;
	return 0;
}