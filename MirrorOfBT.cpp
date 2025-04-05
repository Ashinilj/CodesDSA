class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(!node) return ;
        
        swap(node->left, node->right);
        
        mirror(node->left);
        mirror(node->right);
    }
    
    void levelOrder(Node* root){
        if(!root) return ;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            if(node){
                cout<<node->data<<" ";
                q.push(node->left);
                q.push(node->right);
            }
            else cout<<"N ";
        }
        cout<<endl;
    }
};
