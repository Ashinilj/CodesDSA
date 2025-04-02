class Solution {
  public:
    
    int diameterHelper(Node* root, int &d){
        //if root does not exist diameter will be 0
        if(!root) return 0;
        
        //calculation of left and right height is required bcs 
        //diameter= left height + right height
        int leftHeight= diameterHelper(root->left, d);
        int rightHeight= diameterHelper(root->right, d);
        
        //maximum horizontal distance between any two nodes of same level is calc
        d = max(d, leftHeight + rightHeight);
        
        //returning height is only for recursion purposes
        return 1+ max(leftHeight, rightHeight);
    }
    
    int diameter(Node* root) {
        int d=0;
        diameterHelper(root, d);
        return d;
    }
};
