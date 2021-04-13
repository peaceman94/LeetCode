/*
452. Minimum Number of Arrows to Burst Balloons
There are some spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. The start is always smaller than the end.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.

Given an array points where points[i] = [xstart, xend], return the minimum number of arrows that must be shot to burst all balloons.

 

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
 

Constraints:

0 <= points.length <= 104
points[i].length == 2
-231 <= xstart < xend <= 231 - 1
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
    vector<int> findIntersection( vector<int> lower_interval, vector<int> higher_interval )
    {   
        vector<int> output;
        
        //it is assumed that lower interval has x axis lower
        if( higher_interval[0] <= lower_interval[1] )
        {   
            if(higher_interval[1] <= lower_interval[1])
            {
                return higher_interval;
            }
            else //if(lower_interval[1] <= higher_interval[1])
            {
                return {higher_interval[0], lower_interval[1]};
            }
        };
        return output;
    }
    int findMinArrowShots(vector<vector<int>>& points) {

        if(points.size() == 1) return 1;

        //sort points by thier x starting
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){ return a[0] < b[0]; });
        vector<int> current_int = points[0];

        int arrow_count = 1;
        for(int i = 1; i<points.size(); i++)
        {   
            if(current_int.size() == 0) current_int = points[i];
            current_int = findIntersection(current_int, points[i]);
            if(current_int.size() == 0)
            {
                arrow_count+=1;
                if(i<points.size()) current_int = points[i];
            }
            

            cout << "point #: " << i+1 << " Intersection area: " << current_int[0] << ", " << current_int[1] << " " << arrow_count << endl;
        };
        return arrow_count;
    }
};

int main()
{
    vector<vector<int>> arr;
    //arr = {{1,2}, {3,4}, {5,6}, {100, 200}};
    //arr = {{10,16},{2,8},{1,6},{7,12}};
    arr = {{1,2}, {2,3}, {3,4}, {4,5}};
    Solution sol;
    int output = sol.findMinArrowShots(arr);
    cout << "output is " << output << endl;
    return 0;
}