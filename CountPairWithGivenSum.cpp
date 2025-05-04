class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int count=0;
        unordered_map<int,int> freq;
        
        for(int num: arr){
            int complement= target-num;
            if(freq[complement]>0){
                count+= freq[complement];
            }
            freq[num]++;
        }
        return count;
    }
};
