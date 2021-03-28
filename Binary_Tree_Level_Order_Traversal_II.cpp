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
    int max_level = INT_MIN;
    unordered_map<int, vector<int>> map;
    void helper(TreeNode* root, int level)
    {
        if(root == nullptr) return;
        if(max_level < level)
        {
            max_level = level;
        } 
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> output = {};
        helper(root, 0);
        
        //print solution
        bool inverse = false;
        int level = max_level;
        while(level >= 0)
        {
            output.push_back(map[level]);
            
            level--;
            //inverse = !inverse;
        }
        return output;
    };
};