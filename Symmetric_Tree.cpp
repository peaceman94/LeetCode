/*
101. Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};

class Solution {
public:

  //Naive solution but works
    bool helper(TreeNode* node1, TreeNode* node2)
    {
        bool output = true;
        if(node1->left != nullptr && node2->right != nullptr)
        {
            if(node1->left->val != node2->right->val) return false;
            output = output && helper(node1->left, node2->right);
            if(!output) return false;
        }
        else if(node1->left == nullptr && node2->right == nullptr)
        {
            output = output && true;
        }
        else
        {
            output = output && false;
            if(!output) return false;
        }
        
        if(node1->right != nullptr && node2->left != nullptr)
        {
            if(node1->right->val != node2->left->val) return false;
            output = output && helper(node1->right, node2->left);
        }
        else if(node1->right == nullptr && node2->left == nullptr)
        {
            output = output && true;
        }
        else
        {
            output = output && false;
        }
        return output; 
    };
    
    bool isSymmetric(TreeNode* root) {
        return(helper(root, root));
    };
};



int main()
{
  vector<string> tree_vect = {"1","2","2","null","3","null","3"};
  for(auto x:tree_vect)
    cout << x << endl;

  Solution sol;

  TreeNode *root = new TreeNode();
  root = sol.createTreefromVector(root, tree_vect);
  bool output = sol.isSymmetric(root);
  return 0;
}


