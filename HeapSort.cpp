class Solution {
  public:
    
    void heapify(vector<int> &arr, int n, int i){
        //for 0-based indexing
        int largest= i;
        int left= 2*i+1;
        int right= 2*i+2;
        
        if(left<n && arr[left]>arr[largest]) largest= left;
        if(right<n && arr[right]>arr[largest]) largest=right;
        
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    
    void heapSort(vector<int>& arr) {
        int n = arr.size();
        
        //n/2-1 to n elements are already heapified by default
        //so heapify only 0 to n/2 elements
        for(int i=n/2-1; i>=0; i--){
            heapify(arr, n, i);
        }
        
        //to get ascending order swap first element and last element, pop the last
        //ele and then heapify and repeat it until n=0
        while(n>1){
            swap(arr[0], arr[n-1]);
            n--;
            heapify(arr, n, 0);
        }
    }
};
