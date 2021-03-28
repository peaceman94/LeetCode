/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity sake, each node's value is the same as the node's index (1-indexed). For example, the first node with val = 1, the second node with val = 2, and so on. The graph is represented in the test case using an adjacency list.

Adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

Example 1:


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
Example 4:


Input: adjList = [[2],[1]]
Output: [[2],[1]]
 

Constraints:

1 <= Node.val <= 100
Node.val is unique for each node.
Number of Nodes will not exceed 100.
There is no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.
*/





/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        //if the node is null
        if(node==nullptr)
        {
            Node* temp = nullptr;
            return temp;
        }
        
        //initialize the counters
        unordered_map<int, bool> visited;
        queue<Node*> q;
        unordered_map<int, Node*> map_new;
        
        //push the first node
        Node* newnode = new Node(node->val);
        map_new[newnode->val] = newnode;
        
        visited[node->val] = true;
        q.push(node);        
        
        //run BFS
        while(q.size())
        {
            Node* curr_node = q.front();
            q.pop();
            
            for(auto x: curr_node->neighbors)
            {
                //if the node is not created, create a node
                if(!visited[x->val])
                {
                    Node* newnbornode = new Node(x->val);
                    visited[x->val] = true;
                    map_new[x->val] = newnbornode;
                    q.push(x);
                }
            }   
            
            //since the value is already assigned, assign the n'bors
            vector<Node*> vect;
            for(auto x: curr_node->neighbors)
            {
                vect.push_back(map_new[x->val]);     
            }
            
            //put it in the new map
            Node* new_node = map_new[curr_node->val];
            new_node->neighbors = vect;
            map_new[curr_node->val]=new_node;
        };
        
        //return the first node;
        return newnode; 
    }
};