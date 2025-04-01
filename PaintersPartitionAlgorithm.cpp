bool isPossible(vector<int> &boards, int k, int mid){
    int painterCount=1;
    int boardSum=0;

    for(int i=0; i<boards.size(); i++){
        if(boards[i]+ boardSum <= mid){
            boardSum += boards[i];
        }
        else{
            painterCount++;
            if(painterCount> k || boards[i]> mid){
                return false;
            }
            boardSum = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    if(k> boards.size()) return -1;
    int start=0;
    int end= accumulate(boards.begin(), boards.end(), 0);

    int ans=-1;

    while(start<=end){
        int mid= start+ (end-start)/2;
        if(isPossible(boards, k, mid)){
            ans= mid;
            end= mid-1;
        }
        else{
            start= mid+1;
        }
    }
    return ans;
}
