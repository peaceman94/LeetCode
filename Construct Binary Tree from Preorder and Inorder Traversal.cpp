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
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int p_s, int p_e, int i_s, int i_e) {
        //cout << p_s << ", " << p_e<< ", "<< i_s<< ", "<<i_e<<endl;
        //boundary conditions
        
        //if(p_s > p_e || i_s > i_e) return new TreeNode();
        
        TreeNode* root = new TreeNode(preorder[p_s]);
        
        //now lets find preorder[0] in inorder traversal
        auto it = std::find (inorder.begin(), inorder.end(), preorder[p_s]);
        
        //index at which root is found in inorder
        int i_index = it - inorder.begin();
        
        //size of left subtree
        int size = i_index - i_s + 1;
        
        root->left = nullptr;
        if(p_s+1 <= p_s + size && i_s <= i_index-1)
        {
            root->left = helper(preorder, inorder, p_s+1, p_s + size, i_s, i_index-1 );
        }
        
        root->right = nullptr;
        if(p_s + size <= p_e && i_index+1 <= i_e)
        {
            root->right = helper(preorder, inorder, p_s + size, p_e, i_index+1, i_e );
        }
         
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder )
    {
        int n = preorder.size();
        TreeNode* output = helper(preorder, inorder, 0, n-1, 0, n-1);
        return output;
    }
};
