/*
253. Meeting Rooms II
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
    void print(vector<vector<int>>& intervals)
    {
        for(auto x: intervals)
        {
            for(auto y: x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
        return;
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){ return a[0] < b[0];});
        print(intervals);

        //get a min priority queue to see when is the earliest a loptop gets free
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);

        int count = 1;
        for(int i = 1; i<intervals.size(); i++)
        {
            auto curr_int = intervals[i];
            int earliest_free = pq.top();

            //we dont need  the additiona; laptop
            if(earliest_free <= curr_int[0])
            {
                pq.pop();
                
            }
            else
            {
                count++;
            }
            pq.push(curr_int[1]);
        }
        return count;
    }
};

int main()
{
    vector<vector<int>> intervals = {{7, 10}, {2,4}};
    //vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    Solution sol;
    int output = sol.minMeetingRooms(intervals);\
    cout << "output is " << output << endl;
    return 0;
};

