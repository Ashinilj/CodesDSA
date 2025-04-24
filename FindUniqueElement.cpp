class Solution {
  public:
    int findUnique(vector<int> &arr) {
        int n=arr.size();
        
        int xorAll=0;
        for(int i=0; i<n; i++){
            xorAll ^= arr[i]; //equal nos will cancel out acc to property of xor
        }
        return xorAll;
    }
};
