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
    int helper(TreeNode* root, int curr_depth )
    {
        if(!root) return curr_depth;
        return(max(helper(root->left, curr_depth+1), helper(root->right, curr_depth+1)));
    };
    
    int maxDepth(TreeNode* root) {
        return helper(root, 0);
        
    }
};
