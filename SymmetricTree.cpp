class Solution {
  public:
    bool isMirror(Node* left, Node* right){
        if(!left && !right) return true;    //when both left and right does not exists
        if(!left || !right) return false;   //when either left or right exists and not null
        
        return (left->data==right->data) && isMirror(left->left, right->right) &&
        isMirror(left->right, right->left);
    }
    
    bool isSymmetric(Node* root) {
        if(!root) return true;
        return isMirror(root->left, root->right);
    }
};
