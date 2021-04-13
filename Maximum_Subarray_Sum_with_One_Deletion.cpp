/*
1186. Maximum Subarray Sum with One Deletion
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

 

Example 1:

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
Example 2:

Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.
Example 3:

Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
 

Constraints:

1 <= arr.length <= 105
-104 <= arr[i] <= 104
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
using namespace std;

class Solution {
public:
    int maximumSumBrute(vector<int>& arr) {
        int max_sum = INT_MIN;
        for(int i = 0; i<arr.size(); i++)
        {
            int min_i = INT_MAX;
            int curr_sum = 0;
            int max_sum_curr = INT_MIN;
            for(int j=i; j<arr.size(); j++)
            {
                curr_sum += arr[j];
                if(arr[j] < min_i) min_i = arr[j];
                max_sum_curr = max(max_sum_curr, curr_sum);

                if(i != j && min_i < 0 ) max_sum_curr = max(max_sum_curr, curr_sum - min_i);
                cout << j << " " << max_sum_curr << endl;
            };
            max_sum = max(max_sum_curr, max_sum);
        }
        return max_sum;
    }

    int maximumSum(vector<int>& arr) {

        if(arr.size() == 0) return 0;
        if(arr.size() == 1) return arr[0];

        vector<pair<int, int>> dp(arr.size());
        //first denotes the without skipping part, second continuos part
        dp[0] = {arr[0], 0};
        cout << 0 << " " << arr[0] << " " << 0 << endl;

        //output
        int output = INT_MIN;

        for(int i=1; i<arr.size();i++)
        {
            dp[i].second = max(dp[i-1].second + arr[i], dp[i-1].first );  //skipped + current not skipped OR skip the current
            dp[i].first = max( dp[i-1].first + arr[i], arr[i] );

            output = max(output, dp[i].first);
            output = max(output, dp[i].second);

            cout << i << " " << dp[i].first << " " << dp[i].second << endl;
        };

        return output;
    }

};

int main()
{
    vector<int> arr = {1,-2,-2,3};
    Solution sol;
    int output = sol.maximumSum(arr);
    cout << "output is: " << output << endl;
    return 0;
}