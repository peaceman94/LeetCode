/*
1130. Minimum Cost Tree From Leaf Values
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.

Example 1:

Input: arr = [6,2,4]
Output: 32
Explanation:
There are two possible trees.  The first has non-leaf node sum 36, and the second has non-leaf node sum 32.

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4
 

Constraints:

2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (ie. it is less than 2^31).
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
    unordered_map<string, pair<int, int>> map;
    pair<int, int> helper(vector<int> &arr, int start, int end)
    {
        if(start == end)
        {
            return {arr[start], 0};
        };

        string key = to_string(start) + "_" + to_string(end);
        if(map.find(key) != map.end())
        {
            return map[key];
        }

        int leaf_max = INT_MIN;
        int sum_min = INT_MAX;

        for(int i=start; i<end; i++)
        {   
            auto left = helper(arr, start, i);
            auto right = helper(arr, i+1, end);

            leaf_max = max(leaf_max, left.first);
            leaf_max = max(leaf_max, right.first);
            sum_min = min(sum_min, left.second + right.second + left.first*right.first);
        };
        return map[key] = {leaf_max, sum_min};
    }

    int mctFromLeafValues(vector<int>& arr) {
        auto ans = helper(arr, 0, arr.size()-1);
        return ans.second;
    }
};

int main()
{
    vector<int> arr = {6,2,4};
    Solution sol;
    int output = sol.mctFromLeafValues(arr);
    cout << "output is " << output << endl;
    return 0;
}