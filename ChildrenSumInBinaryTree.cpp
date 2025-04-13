
class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    bool check(Node* root){
        if(!root || (!root->left && !root->right)) return true;
        
        bool left= check(root->left);
        bool right= check(root->right);
        
        int leftData= root->left ? root->left->data : 0;
        int rightData= root->right ? root->right->data : 0;
        
        bool curr= (root->data == leftData + rightData);
        
        return left && right && curr;
    }
    int isSumProperty(Node *root)
    {
        return check(root) ? 1: 0;
    }
};
