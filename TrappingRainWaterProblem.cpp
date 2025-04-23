class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int leftMax=0, rightMax=0, water=0;
        
        int n= arr.size();
        if(n<=1) return 0;
        
        int left=0, right=n-1;
        
        while(left<right){
            if(arr[left]<=arr[right]){
                if(arr[left]<leftMax)
                    water += leftMax-arr[left];
                else
                    leftMax= arr[left];
                    
                left++;
            }
            
            else{
                if(arr[right]<rightMax)
                    water += rightMax-arr[right];
                else
                    rightMax= arr[right];
                    
                right--;
            }
        }
        return water;
    }
};
