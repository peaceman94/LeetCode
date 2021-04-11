/*

547. Number of Provinces
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/

#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<set>
#include <utility>
using namespace std;

struct Node
{
	int value;
	Node* parent;
	int rank;
};

class union_find{
public:
	vector<Node*> map;

	//constructor
	union_find(int n)
	{
		vector<Node*> temp(n);
		map = temp;
	}
	
	//make_set
	void make_set(int root)
	{
		Node* output = new Node();
		
		//parent - put its value as root
		Node* parent = new Node();
		parent->value = root;
		output->parent = parent;

		output->value = root;
		output->rank = 0;

		map[root] = output;
		return;
	};

	//find root
	Node* find_root(int val)
	{
		Node* curr_node = map[val];

		if(curr_node->value == curr_node->parent->value) return curr_node;
	    Node* output = find_root(curr_node->parent->value);

	    //path collapse hueristics
	    curr_node->parent = output;
	    return output;
	}

	void union_do( Node* node_1, Node* node_2 )
	{
		Node* root_1 = find_root(node_1->value);
		Node* root_2 = find_root(node_2->value);

		if(root_1 == root_2)
		{
			//its already an union
			return;
		}

		//rank hueristics
		if(root_1->rank < root_2->rank)
		{
			root_1->parent = root_2;
		}
		else
		{
			root_2->parent = root_1;
			if(root_1->rank == root_2->rank)
			{
				root_1->rank++;
			}
		}
		return;
	}
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected){
		union_find uf(isConnected.size());
		for(int i=0; i<isConnected.size();i++) uf.make_set(i);
		
		//not traverse the matrix
		for(int i=0; i<isConnected.size();i++)
		{
			for(int j=i; j<isConnected.size(); j++)
			{
				if(isConnected[i][j])
				{
					uf.union_do(uf.find_root(i), uf.find_root(j));
				}
			}
		}

		//traverse the map to count provinces
		int provinces = 0;
		for(int i=0; i<uf.map.size(); i++)
		{
			if(uf.map[i]->value == uf.map[i]->parent->value) provinces++;
		}

        return provinces;
    }
};

int main()
{
	vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
	Solution sol;

	int output = sol.findCircleNum(isConnected);
	cout << "output is " << output << endl;
	return 0;
}