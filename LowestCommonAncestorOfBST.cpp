class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(!root) return nullptr;
        
        // if both are less than root then go to left subtree
        if(n1->data < root->data && n2->data < root->data){
            return LCA(root->left, n1, n2);
        }
        //if both are greater than root then go to right subtree
        if(n1->data > root->data && n2->data > root->data){
            return LCA(root->right, n1, n2);
        }
        
        //if root is in between both of the val or one val is equal to root 
        //then root is the LCA 
        return root;
    }
};
