class Solution {
  public:
    bool isPossible(vector<int> &stalls, int k, int mid){
        int cowCount=1;
        int pos= stalls[0];
        
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i]-pos >= mid){
                cowCount++;
                if(cowCount==k) return true;
                pos= stalls[i];
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int n= stalls.size();
        int start=0;
        int end= stalls[n-1]-stalls[0];
        int ans=-1;
        
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(stalls, k, mid)){
                ans= mid;
                start= mid+1;
            }
            else{
                end= mid-1;
            }
        }
        return ans;
    }
};
