class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        //boyer moore voting algorithm
        int n= arr.size();
        int target= n/2;
        int candidate=-1, count=0;
        
        //check for suitable candidate that could be our ans
        //count will be greater than 0 if any suitable candidate exists
        for(int num: arr){
            if(count==0){
                candidate= num;
                count=1;
            }
            else if(num==candidate) count++;
            else count--;
        }
        
        //reset count and calculate the actual occurences of candidate found
        count=0;
        for(int num: arr){
            if(num==candidate) count++;
        }
        
        return (count>target) ? candidate : -1;
    }
};
