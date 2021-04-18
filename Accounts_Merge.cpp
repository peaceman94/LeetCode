/*
721. Accounts Merge

Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Example 2:

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 

Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 
1 <= accounts[i][j] <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.
*/

#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include <utility>
using namespace std;

class union_find
{
public:
	vector<int> parent;
	vector<int> rank;
	union_find(int n)
	{
		vector<int> temp(n, -1);
		parent = temp;

		vector<int> temp2(n, -1);
		rank = temp2;
	}

	void make_set(int i)
	{
		parent[i] = i;
		rank[i] = 1;
	}

	int find_key(int i)
	{
		if(i == parent[i]) return i;
		parent[i] = find_key(parent[i]);
		return parent[i];
	}

	void union_do(int i, int j)
	{
		//cout << "unioning: " << i << ", " << j << endl;

		int root_1 = find_key(i);
		int root_2 = find_key(j);
		if(root_1 == root_2) return;
		if(rank[root_1] > rank[root_2])
		{
			parent[root_2] = root_1;
			//cout << "changing the parent of " << root_2 << " to " << root_1 << endl;
		}
		else
		{
			parent[root_1] = root_2;
			if(rank[root_1] == rank[root_2])
			{
				rank[root_2] += 1; 
			}
			//cout << "changing the parent of " << root_1 << " to " << root_2 << endl;
		}
		return;
	}
};

class Solution {
public:

	unordered_map<string, vector<string> > graph;
	void createGraph(vector<vector<string>>& accounts)
	{
		for(auto acc: accounts)
		{
			string name = acc[0];
			string pemail = acc[1];
			for(int i=2; i<acc.size(); i++)
			{
				graph[pemail].push_back(acc[i]);
				graph[acc[i]].push_back(pemail);
			}
		}
		return;
	};

	void DFS(string curr_email, unordered_set<string> &visited, vector<string> &merged_acc)
	{
		merged_acc.push_back(curr_email);

		for(string nbor: graph[curr_email])
		{
			if(visited.find(nbor) != visited.end()) continue;
			visited.insert(nbor);
			DFS(nbor, visited, merged_acc);
		}
		return;

	}

    vector<vector<string>> accountsMergeDFS(vector<vector<string>>& accounts) {
    	createGraph(accounts);

    	//output
    	vector<vector<string>> output;

    	//maintain parent and visited array
    	unordered_set<string> visited;

    	for(int i=0; i<accounts.size(); i++)
    	{
    		//put the parent of current as NILL
    		string name = accounts[i][0];
			string pemail = accounts[i][1];
			
			//in DFS if already visited, move on
			if(visited.find(pemail) != visited.end()) continue;

			vector<string> merged_acc;
			visited.insert(pemail);
			
			DFS(pemail, visited, merged_acc);

			//now create output already
			sort(merged_acc.begin(), merged_acc.end());
			vector<string> curr_output = {name};
			curr_output.insert( curr_output.end(), merged_acc.begin(), merged_acc.end() );
			output.push_back(curr_output);
    	};
        return output;
    }

    unordered_map<string, int> emailtoid;
    unordered_map<string, string> emailtoname;
    void createEmailToId(vector<vector<string>>& accounts)
    {
    	int id = 0;
		for(auto acc: accounts)
		{
			string name = acc[0];
			for(int i=1; i<acc.size(); i++)
			{
				if(emailtoid.find(acc[i]) == emailtoid.end())
				{
					emailtoid[acc[i]] = id++;
					emailtoname[acc[i]] = name;
				};
			};
		};
    };

    vector<vector<string>> createUF(vector<vector<string>>& accounts)
    {
    	createEmailToId(accounts);
    	union_find uf(emailtoname.size());

		for(auto x: emailtoname)
		{
			uf.make_set(emailtoid[x.first]);
		};

		for(auto acc: accounts)
		{
			string name = acc[0];
			string pemail = acc[1];
			for(int i=2; i<acc.size(); i++)
			{				
				uf.union_do(uf.find_key(emailtoid[pemail]), uf.find_key(emailtoid[acc[i]]) );
			};
		};

		//now parse the solution
		unordered_map<int, vector<string>> ans;
		for(auto x: emailtoname)
		{
		    int index = uf.find_key(emailtoid[x.first]);
			if(ans.find(index) == ans.end())
			{
				ans[index] = {x.first};
			}
			else
			{
				ans[index].push_back(x.first);
			}
		};

		vector<vector<string>> output;
		for(auto x: ans)
		{
			vector<string> curr_output = x.second;
			sort(curr_output.begin(), curr_output.end());
			curr_output.insert(curr_output.begin(), emailtoname[curr_output[0]]);
			output.push_back(curr_output);
		}
		return output;
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    	auto output = createUF(accounts);
    	return output;
    }


};

int main()
{
	vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};

	Solution sol;
	auto output = sol.accountsMerge(accounts);
	for(auto acc: output)
	{
		for(auto x: acc) cout << x << " ";
		cout << endl;
	}
	return 0;
}


