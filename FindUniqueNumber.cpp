class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int xorAll=0;
        for(int i: arr){
            xorAll^=i;
        }
        return xorAll;
    }
};
