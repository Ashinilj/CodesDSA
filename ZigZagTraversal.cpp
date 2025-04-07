class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
        if(!root) return ans;

        queue<Node*> q;
        q.push(root);
        bool isLeftRight= true;

        while(!q.empty()){
            int size= q.size();
            vector<int> temp(size);

            for(int i=0; i<size; i++){
                Node* node= q.front();
                q.pop();

                int index= isLeftRight ? i : (size-1-i);
                temp[index]= node->data;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.insert(ans.end(), temp.begin(), temp.end());
            isLeftRight= !isLeftRight;
        }
        return ans;
    }
};
