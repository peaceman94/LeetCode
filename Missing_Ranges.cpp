/*
163. Missing Ranges
*/

#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include <numeric>
#include <algorithm>
#include <queue>
#include <limits>
#include <climits> 
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
    {
        vector<string> output = {};

        int prev = lower;
        int curr;
        bool add_one = false;

        for(int i=0; i<nums.size(); i++)
        {
            curr = nums[i];
            //missing numbers
            if(curr-prev >= 1)
            {
                int a = (add_one) ? prev + 1: prev;
                int b = curr-1;
                if(a == b)
                {
                    output.push_back(to_string(a));
                }
                else if(a < b)
                {
                    output.push_back(to_string(a) + "->" + to_string(b));
                }
            };
            prev= curr;
            add_one = true;
        }

        //take care of the final number
        curr = upper;
        if(curr-prev >= 1 || (curr == prev && !add_one))
        {
            int a = (add_one) ? prev + 1: prev;
            int b = curr;
            if(a == b)
            {
                output.push_back(to_string(a));
            }
            else if(a < b)
            {
                output.push_back(to_string(a) + "->" + to_string(b));
            }
        }
        return output;
    };
};

int main()
{
    vector<int> nums = {1, 3, 50, 75};
    int lower = 0;
    int upper = 99;

    Solution sol;
    auto output = sol.findMissingRanges(nums, lower, upper);

    for(auto x: output)
        cout << x << " ";
    cout << endl;
};