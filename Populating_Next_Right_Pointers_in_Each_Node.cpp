/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connectHelper(Node* root, Node *temp) {
        if(root == nullptr) return root;
        if(root->left == nullptr) return root;
        root->left->next = root->right;
        root->right->next = temp;
        root->left = connectHelper(root->left, root->right->left);
        
        if(temp == nullptr)
        {
            root->right = connectHelper(root->right, temp);
        }
        else
        {
            root->right = connectHelper(root->right, temp->left);
        }
          
        return(root);
    };
    Node* connect(Node* root) {
        Node* output = connectHelper( root, nullptr);
        return output;
    }
};