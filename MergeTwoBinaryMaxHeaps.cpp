class Solution{
    public:
    void heapify(vector<int> &arr, int n, int i){
        int largest=i;
        int left= 2*i+1;
        int right= 2*i+2;
        
        if(left<n && arr[left] > arr[largest]) largest=left;
        if(right<n && arr[right] > arr[largest]) largest= right;
        
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        for(int i: a) ans.push_back(i);
        for(int i: b) ans.push_back(i);
        
        int size= ans.size();
        for(int i= size/2-1; i>=0; i--){
            heapify(ans, size, i);
        }
        return ans;
    }
};
