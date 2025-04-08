class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        vector<int> result;
        if(!root) return result;
        
        queue<Node*> q;
        stack<int> st;
    
        q.push(root);
    
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
    
            st.push(node->data);
    
            // Push right first so left is processed last when reversed
            if(node->right) q.push(node->right);
            if(node->left) q.push(node->left);
        }
    
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
    
        return result;
    }

};
