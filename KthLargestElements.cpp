class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        //we do not use maxheap bcs it gives o log n complexity whereas minheap gives o log k complexity
        //in max heap we need to create a maxheap of n size and then remove k elements but in minheap we only need to create a minheap of size k
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int ele: arr){
            minHeap.push(ele);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        
        vector<int> ans(k);
        for(int i=k-1; i>=0; i--){
            ans[i]= minHeap.top();
            minHeap.pop();
        }
        return ans;
    }
};
