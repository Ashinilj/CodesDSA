class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        queue<node*> q;
        q.push(root0);
        
        int i=1;
        
        while(!q.empty() && i<vec.size()){
            node* temp= q.front();
            q.pop();
            
            if(i<vec.size() && vec[i] != -1){
                temp->left= newNode(vec[i++]);
                q.push(temp->left);
            }
            
            if(i<vec.size() && vec[i] != -1){
                temp->right= newNode(vec[i++]);
                q.push(temp->right);
            }
        }
    }

};
