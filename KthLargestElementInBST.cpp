class Solution {
  public:
    //reverse LOT will give ele in descending order (right-node-left)
    void largestHelper(Node *root, int &k, int &ans){
        if(!root || k==0) return ;
        
        //as it is a bst largest value nodes will be on the right side
        //sp traverse to right first
        largestHelper(root->right, k, ans);
        
        //k gets decremented during backtracking to keep the count
        k--;
        if(k==0){
            ans= root->data;
            return;
        }
        
        //if element is not yet found then traverse left side
        largestHelper(root->left, k , ans);
    }
    
    int kthLargest(Node *root, int k) {
        //if k is larger than no of nodes or for some reason ans is not found
        int ans= -1;
        largestHelper(root, k, ans);
        return ans;
    }
};
