/*
473. Matchsticks to Square
Medium

757

64

Add to List

Share
Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.
Note:
The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.
*/

#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<set>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool isPossibleGlobal = false;
    void checkPossibility(vector<int> &nums, int n, int side, vector<int> &sums, int start_index)
    {
        //do not even check if its possible
        if(isPossibleGlobal) return;
        
        if(start_index >= n)
        {
            //check if all elements of sums are equal to side
            //bool output = true;
            //for(int i=0; i<4; i++) output = output && sums[i]==side;
            isPossibleGlobal = sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == sums[3];
            //isPossibleGlobal = output;
            return;
        }

        //for element at start_index, try allocating it to all the sides
        for(int j=0; j<4; j++)
        {
            if(sums[j] + nums[start_index] > side) continue;

            sums[j] += nums[start_index];
            checkPossibility(nums,n, side, sums, start_index + 1);
            sums[j] -= nums[start_index];
        };

        return;
    }

    bool makesquare(vector<int>& nums ) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> sums(4, 0);  //to store the sum of each side so far
        
        //base condition
        if(n<4 || sum%4 != 0) return false;

        //sorting makes it run faster and terminate faster (reverse sorting)
        sort(nums.begin(), nums.end(), greater<int>());
        
        checkPossibility(nums,n,sum/4,sums,0);
        return isPossibleGlobal;
    }

};

int main()
{
    //vector<int> nums = {2,2,2,2};
    //vector<int> nums = {10,6,5,5,5,3,3,3,2,2,2,2};
    vector<int> nums = {12,8,12,16,20,24,28,32,36,40,44,48,52,56,60};
    Solution sol;
    //bool output = sol.makesquareBruteForce(nums);
    bool output = sol.makesquare(nums);
    cout << "solution is: " << output << endl;
    return 0;
}