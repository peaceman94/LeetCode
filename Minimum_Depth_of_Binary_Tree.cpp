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
    int min_h = INT_MAX;
    void helper(TreeNode* root, int level)
    {
        if(level > min_h) return;
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(min_h > level) min_h = level;
            return;
        }
        helper(root->left, level+1);
        helper(root->right, level+1);
        return;
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        helper(root, 1);
        return min_h;
    }
};