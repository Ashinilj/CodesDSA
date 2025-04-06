class Solution {
public:
    int check(TreeNode* root){
        if(!root) return 0;
        
        int leftHeight= check(root->left);
        if(leftHeight==-1) return -1;

        int rightHeight= check(root->right);
        if(rightHeight==-1) return -1;

        if(abs(leftHeight-rightHeight) > 1) return -1;
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};

/*
The logic here is to create a helper fn check and count the height of the tree. Check fn will return the height of the tree if it is balanced.
It will return -1 if tree is unbalanced. 
*/
