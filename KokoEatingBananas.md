class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left= 1; //minimum no of bananas koko can eat
        int right= *max_element(piles.begin(), piles.end()); //max no of bananas koko can eat

        while(left<right){
            int mid= left + (right-left)/2; //initial speed will be mid
            int hours= calculateHours(piles, mid); //calc total time taken

            //less than minimum h means move to the left side because we 
            //can minimize the integer further, and vice-versa
            if(hours<=h) right= mid; 
            else left= mid+1;
        }
        return left;
    }

    int calculateHours(vector<int> &piles, int hourly){
        long long hours= 0;
        for(int pile: piles){
            hours += ceil(double(pile)/double(hourly));
        }
        return hours;
    }
};
