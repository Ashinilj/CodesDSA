class Solution {
  public:
    int countNodes(Node* root){
        if(!root) return 0;
        return 1+ countNodes(root->left) + countNodes(root->right);
    }
    
    bool isComplete(Node* root, int index, int totalNodes){
        if(!root) return true;
        if(index >= totalNodes) return false;
        return isComplete(root->left, 2*index+1, totalNodes) &&
        isComplete(root->right, 2*index+2, totalNodes);
    }
    
    bool isHeapProperty(Node* root){
        if(!root->left && !root->right) return true;
        
        if(root->right==nullptr) {
            return (root->data >= root->left->data) && isHeapProperty(root->left); 
        }
        
        else{
            return (root->data >= root->left->data) &&
            (root->data >= root->right->data) && 
            isHeapProperty(root->left) &&
            isHeapProperty(root->right);
        }
    }
    
    bool isHeap(struct Node* tree) {
        int totalNodes= countNodes(tree);
        return isComplete(tree, 0, totalNodes) && isHeapProperty(tree);
    }
};
