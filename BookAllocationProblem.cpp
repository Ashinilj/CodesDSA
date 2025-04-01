bool isPossibleSolution(vector<int>& arr, int n, int m, int mid){
    int studentCount=1;
    int pageSum=0;

    for(int i=0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m || arr[i] > mid){
                return false;
            }
            pageSum = arr[i];
        }
        
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    int start=0;
    int sum=0;
    if (m > n) return -1;

    for(int ele: arr){
        sum += ele;
    }
    int end=sum;
    int ans = -1;

    while(start<=end){
        int mid= start + (end-start)/2;
        if(isPossibleSolution(arr, n, m , mid)){
            ans = mid;
            end= mid -1;
        }
        else{
            start= mid+1;
        }
    }
    return ans;
}
