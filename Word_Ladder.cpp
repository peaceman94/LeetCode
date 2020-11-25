/*
127. Word Ladder

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<iostream>
using namespace std;


class Solution {
public:
	unordered_map<string, int> level;
	unordered_map<string, vector<string> > allCombo;
	void createEdges(string s, string e, vector<string>&edg )
	{
		edg.push_back(s);
		int l = s.size();
		for(int i = 0; i <edg.size(); i++)
		{
			string word = edg[i];
			for(int j = 0; j<l; j++)
			{
				string newword = word.substr(0, j) + "*" + word.substr(j+1);
				allCombo[newword].push_back(word);
			}
		}

		/*
		//print allCombo
		for(auto i = allCombo.begin(); i!=allCombo.end(); i++)
		{
			string pat = i->first;
			vector<string> words = i->second;
			cout << pat << ": ";
			for(int j=0; j<words.size(); j++)
			{
				cout << words[j] << " ";
			}
			cout << endl;

		}
		*/
	}

	int BFS( string s, string target )
	{
		level[s] = 0;
		vector<string> q{s};
		int l = s.size();

		int lev = 1;
		while(q.size() )
		{
			vector<string> curr;
			for(int k = 0; k<q.size(); k++)
			{
				string word = q[k];
				//cout << "working on word: " << word << endl;
				for(int i = 0; i<l; i++)
				{
					string newword = word.substr(0, i) + "*" + word.substr(i+1);
					vector<string> edges = allCombo[newword];
					
					for(int j = 0; j<edges.size(); j++)
					{
						string subword = edges[j];
						if(subword == word) continue;
						//cout << "subword is: " << subword << endl;
						if(level.find(subword) == level.end() )
						{
							level[subword] = lev;
							curr.push_back(subword);
							if(subword == target) return lev +1;
						}
					}
				}
			}
			
			q = curr;
			//cout << lev << endl;
			lev++;
		}

		return 0;
	}

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		

		/*
		//print edge
		for(auto i = wordList.begin(); i != wordList.end(); i++)
		{
			cout << "Vertex: " << *i << ":  ";
			for(int j = 0; j < edges[*i].size(); j++)
			{
				cout << edges[*i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
		*/

    	createEdges(beginWord,endWord,wordList);
    	//return 0;
		int output = BFS(beginWord, endWord);
	 	return output;       
	 }
};

int main()
{
	/*
	string s = "hit";
	string e = "cog";
	vector<string> edg{ "hot","dot","dog","lot","log", "cog"};
	*/

	
	string s = "a";
	string e = "c";
	vector<string> edg{ "a", "b", "c"  };	
	

	Solution sol;
	int output = sol.ladderLength(s,e,edg);
	cout << "output is : " << output << endl;
	return 0;

}