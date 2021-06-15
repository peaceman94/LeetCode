/*
42. Trapping Rain Water
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
    int trap(vector<int>& height) {
        int n = height.size();
        //we will  reate 2 arrays left and right
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i=1; i<n; i++)
            left[i] = max(left[i-1], height[i-1]);
        
        for(int i=n-2; i>=0; i--)
            right[i] = max(right[i+1], height[i+1]);

        int water = 0;
        for(int i=0; i<n; i++)
        {
            int curr_water = min(left[i], right[i]) - height[i];
            if(curr_water > 0) water += curr_water;
        }
        return water;
    }
};

int main()
{
    //vector<int> words = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> words = {4,2,0,3,2,5};
    Solution sol;
    int output = sol.trap(words);
    cout << "output is: " << output << endl;
    return 0;
}