/*
102. Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
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
class Solution {
public:
    unordered_map<int, vector<int>> map;
    void helper(TreeNode* root, int level)
    {
        if(root == nullptr) return;
        if(map.find(level) != map.end())
        {
            map[level].push_back(root->val);
        }
        else
        {
            vector<int> temp;
            map[level] = temp;
            map[level].push_back(root->val);
        };
        
        if(root->left != nullptr)
        {
            helper(root->left, level+1);
        };
        if(root->right!= nullptr)
        {
            helper(root->right, level+1);
        }
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output = {};
        helper(root, 0);
        
        //print solution
        bool iter = true;
        int level = 0;
        while(iter)
        {
            if(map.find(level) == map.end())
            {
                iter = false;
                continue;
            }
            
            output.push_back(map[level]);
            level++;
        }
        return output;
    }
};