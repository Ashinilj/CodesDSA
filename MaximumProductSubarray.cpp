class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n= arr.size();
        //we will keep track of both min and max product
        int maxProduct = arr[0];
        int minProduct = arr[0];
        int result = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) {
                //when ele is -ve min product can become max product
                //ans max product can become small so swap
                swap(maxProduct, minProduct);
            }

            maxProduct = max(arr[i], maxProduct * arr[i]);
            minProduct = min(arr[i], minProduct * arr[i]);

            result = max(result, maxProduct);
        }
        return result;
    }
};
