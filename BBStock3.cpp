/*
123. Best Time to Buy and Sell Stock III

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
Example 4:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105

[Solution here]: https://www.youtube.com/watch?v=2E0-_LtUPiE
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	//divide and concquer approach
    int maxProfit_D_C(vector<int>& prices) {
        int m = prices.size();
        if(m==0)return 0;
        if(m==1) return 0;

        vector<int> pfl;
        vector<int> pfr;

        //handle the left array
        int min = prices[0];
        pfl.push_back(0);
        for(int i=1; i<m;i++){
    		if(prices[i] < min){
    			min = prices[i];
    		}
    		int curr_pf = prices[i] - min;
    		pfl.push_back(max(pfl[i-1], curr_pf));
    		//cout << pfl[i] << endl;;
        }

        //handle the right array
        int maxp = prices[m-1];
        for(int i = 0; i<m; i++){
        	pfr.push_back(0);
        }
        
        for(int i=m-2; i>=0; i--){
        	if(prices[i] > maxp){
        		maxp = prices[i];
        	}
        	int curr_pf = maxp - prices[i];
        	pfr[i] = max(pfr[i+1], curr_pf);
        	//cout << pfr[i] << endl;;
        }

        int maxprofit = 0;
        for(int i=0; i<m;i++){
        	if( pfl[i] + pfr[i] > maxprofit){
        		maxprofit = pfl[i] + pfr[i];
        	}
        }
        return maxprofit;
    }

    //dynamic programming approach to be done

};

int main(){

	vector<int> p;
	int temp;
	while(cin >> temp) p.push_back(temp);

	Solution sol;
	int output = sol.maxProfit_D_C(p);
	cout << "output is: " << output << endl;
	return output;
}