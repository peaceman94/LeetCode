/*
243. Shortest Word Distance

Given an array of strings wordsDict and two different strings that already exist in the array word1 and word2, return the shortest distance between these two words in the list.

 

Example 1:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "coding", word2 = "practice"
Output: 3
Example 2:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1
 

Constraints:

1 <= wordsDict.length <= 3 * 104
1 <= wordsDict[i].length <= 10
wordsDict[i] consists of lowercase English letters.
word1 and word2 are in wordsDict.
word1 != word2
*/

#include<vector>
#include<iostream>
#include <cstdlib>
#include<unordered_map>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //O(nlogn)
    int applyBinSearchForAll(vector<int> arr1, vector<int> arr2)
    {
        int global_output = INT_MAX;
        for(int num: arr2)
        {
            //now we need to find nearest element in this array
            int n = arr1.size();
            int start = 0;
            int end = n-1;
            int output = INT_MAX;
            while(start <= end)
            {
                int mid = (start + end)/2;
                if(arr1[mid] == num)
                    return 0;
                output = min(output, abs(arr1[mid]  - num));

                if(arr1[mid] > num)
                {
                    end = mid-1;
                }
                else
                {
                    start = mid + 1;
                }

            }
            global_output = min(global_output, output);
        }
        return global_output;
    }

    //nlogn solution
    int shortestDistanceBrute(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string, vector<int>> positions;

        //o(n)
        for(int i=0; i<wordsDict.size(); i++)
        {
            if(positions.find(wordsDict[i]) == positions.end())
                positions[wordsDict[i]] = {};
            positions[wordsDict[i]].push_back(i);
        }

        int output = applyBinSearchForAll(positions[word1], positions[word2]);
        return output;
    }

    //o(n) solution
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int output = wordsDict.size();
        int last1 = -1;
        int last2 = -1;
        for(int i=0; i<wordsDict.size(); i++)
        {
            if(wordsDict[i] == word1)
                last1 = i;
            if(wordsDict[i] == word2)
                last2 = i;
            if(last1 != -1 && last2 != -1)
                output = min(output, abs(last1-last2));
        }
        return output;
    }
};

int main()
{
    vector<string> worddict = { "practice", "makes", "perfect", "coding", "makes"  };
    string word1 = "coding";
    string word2 = "makes";

    Solution sol;
    int output = sol.shortestDistance(worddict, word1, word2);
    cout <<  "output is: " << output << endl;
    return 0;
}