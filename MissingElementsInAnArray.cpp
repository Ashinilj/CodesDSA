class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int n = arr.size() + 1;
        int xorAll = 0;
        int xorArr = 0;
        
        // XOR all numbers from 1 to n
        for (int i = 1; i <= n; ++i) {
            xorAll ^= i;
        }
        
        // XOR all elements of the array
        for (int num : arr) {
            xorArr ^= num;
        }
        
        // XOR of above two will be the missing number
        return xorAll ^ xorArr;
    }
};
