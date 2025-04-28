class Solution {
public:
    bool isHeap(Node* tree) {
        if(!tree) return true;
        
        //to check if non null node is found after a null node 
        bool nullChildSeen= false;
        queue<Node*> q;
        q.push(tree);
        
        //using level order traversal
        while(!q.empty()){
            Node* curr= q.front();
            q.pop();
            
            //check if left child val is greater than curr node
            if(curr->left){
                if(nullChildSeen) return false; //if non null node is found after null node
                if(curr->data < curr->left->data) return false;
                q.push(curr->left);
            }
            else nullChildSeen= true; //when null node is found val is set to true
            
            if(curr->right){
                if(nullChildSeen) return false;
                if(curr->data < curr->right->data) return false;
                q.push(curr->right);
            }
            else nullChildSeen= true;
        }
        return true;
    }
};
