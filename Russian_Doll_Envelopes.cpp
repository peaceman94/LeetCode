/*
354. Russian Doll Envelopes

You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
        //Sort and then longest increasing subsequence in y space
        int maxEnvelopes(vector<vector<int>>& envelopes) {

        /*
        //print the 2d array
        for(int i = 0; i< envelopes.size(); i++)
        {
            cout << envelopes[i][0] << " " << envelopes[i][1] << endl;
        }
        */

        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 0);
        for(int i = 0; i< envelopes.size(); i++)
        {
            dp[i] = 1;
            for(int j = 0; j<=i; j++)
            {
                if( (envelopes[j][1] < envelopes[i][1]) && (envelopes[j][0] < envelopes[i][0]) )
                {
                    //cout << "hello" << endl;
                    dp[i] = max(dp[i], dp[j] + 1);
                }   
            }
            //cout << "I is: " << i << " dp is: " << dp[i] << endl;
        }              
        int ret = 0;
        for(int i = 0; i< envelopes.size(); i++)
        {
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

int main(){

/*
2 100
3 200
4 300
5 250
5 400
5 500
6 360
6 370
7 380
*/
    vector<vector<int>> vec {{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}};
    Solution sol;
    int output = sol.maxEnvelopes(vec);
    cout << output << endl;
    return 0;
}
