/*
735. Asteroid Collision
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
Example 4:

Input: asteroids = [-2,-1,1,2]
Output: [-2,-1,1,2]

Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.

Constraints:
2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        vector<int> output;
        for(int i=0; i<asteroids.size(); i++)
        {
            if(asteroids[i] > 0)
            {
                //if positive put it in stack
                stack.push_back( asteroids[i] );
            }
            else
            {
                //if negative, pull out any elements in stack to resolve collisions - else put the result in output
                if(stack.size() == 0)
                {
                    output.push_back(asteroids[i]);
                }
                else
                {
                    //pull the first element
                    int pos = stack.back();
                    stack.pop_back();
                    int flag = true;  //indicates that the stack is not empty
                    while( abs(pos) < abs(asteroids[i]) )
                    {
                        if(stack.size() == 0)
                        {
                            //this means that there is nothing going on right and tack is empty... put left into output and break;
                            output.push_back(asteroids[i]);
                            flag = false;
                            break;
                        }
                        pos = stack.back();
                        stack.pop_back();
                    };

                    //if stack is not emopty in the process
                    if(flag)
                    {
                        if(abs(pos) == abs(asteroids[i])) continue;
                        stack.push_back(pos);
                    };
                }
            }
        };
        if(stack.size() > 0)
        {
            output.insert(output.end(), stack.begin(), stack.end());
        }

        return output;
    }
};

int main()
{
    vector<int> ast = {-2,-1,1,2};
    Solution sol;
    vector<int> output = sol.asteroidCollision(ast);
    for(auto x: output) cout << x << " ";
    cout << endl;
    return 0;
}