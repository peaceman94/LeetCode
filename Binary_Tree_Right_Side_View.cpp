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
    vector<int> output = {};
    int depth_covered = 0;
    void helper(TreeNode* root, int depth)
    {
        //return for null cases
        if(root == nullptr) return;
        
        //we are deeper than the depth covered
        if(depth>depth_covered)
        {
            depth_covered = depth;
            output.push_back(root->val);
        };
        
        //explore right first and left second
        helper(root->right, depth+1);
        helper(root->left, depth+1);
        
        return;
    };
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return output;
        helper(root, 1);
        return output;
    }
};