class Solution {
public:
    void trackParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();
            if(curr->left){
                parent_track[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right]= curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parent_track;
        trackParent(root, parent_track, target);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]= true;

        int curr_level=0;
        while(!q.empty()){
            int sz= q.size();
            if(curr_level++ == k) break;
            for(int i=0; i<sz; i++){
                TreeNode* curr= q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]= true;
                }

                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]= true;
                }

                if(parent_track[curr] && !vis[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]]= true;
                }
            }
        }
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};
