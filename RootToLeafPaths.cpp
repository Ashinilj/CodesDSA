class Solution {
  public:
    void dfs(Node* node, vector<int> &temp, vector<vector<int>> &ans){
      //base condition to terminate recursion
        if(!node) return ;

      //pushes the value of root node first
        temp.push_back(node->data);

      //when leaf node is reached temp path is stored to ans
        if(!node->left && !node->right){
            ans.push_back(temp);
        }

      //if leaf node is not reached then first go to L then R
        else{
            dfs(node->left, temp, ans); //when all left nodes are push right nodes will be pushed after the pop through backtracking
            dfs(node->right, temp, ans);
        }
      //pop back values from temp while backtracking
        temp.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root, temp, ans);
        return ans;
    }
};
