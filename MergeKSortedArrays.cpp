class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq; //minheap
        
        //push first element of every array
        for(int i=0; i<K; i++){
            pq.push({arr[i][0], {i,0}}); //heapifies automatically during insertion
        }
        
        vector<int> ans;
        while(!pq.empty()){
            auto curr= pq.top();
            pq.pop();
            
            int val= curr.first;
            int row= curr.second.first;
            int col= curr.second.second;
            
            ans.push_back(val); //pushes val at top of min heap every time
            
            //next element exists near the minimum element push that val in queue
            //it will heapify again automatically and lowest ele will be at top
            if(col+1<K){
                pq.push({arr[row][col+1], {row, col+1}});
            }
        }
        return ans;
    }
};
