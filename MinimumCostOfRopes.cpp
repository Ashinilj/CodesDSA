class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        for(int ele: arr){
            minHeap.push(ele);
        }
        
        long long cost=0;
    
        while(minHeap.size() > 1){
            long long a= minHeap.top();
            minHeap.pop();
            long long b= minHeap.top();
            minHeap.pop();
            
            long long sum = a+b;
            cost += sum;
            minHeap.push(sum);
        }
        return cost;
    }
};
