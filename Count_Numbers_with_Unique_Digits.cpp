/*
357. Count Numbers with Unique Digits

Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10^n.

Example:

Input: 2
Output: 91 
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
             excluding 11,22,33,44,55,66,77,88,99
 

Constraints:

0 <= n <= 8
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> map;
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;

        if(map.find(n) != map.end())
            return map[n];
        
        int output = 9;
        for(int i=2; i<=n; i++)
        {
            output *= (10 - i + 1);
        }
        output += countNumbersWithUniqueDigits(n-1);

        map[n] = output;
        return output;
    }
};

int main()
{
    int n =3;
    Solution sol;
    int output = sol.countNumbersWithUniqueDigits( n );
    cout << "output is " << output << endl;
    return 0;
}