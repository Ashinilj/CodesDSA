class Solution {
  public:
    bool isPalindrome(int n) {
        //optimal approach
        if(n<0 || (n%10==0 && n!=0)) return false;
        
        int reversed=0;
        
        //reversing half of the number
        while(n>reversed){
            reversed = reversed*10 + n%10;
            n /= 10;
        }
        
        //for even digits || for odd digits
        return (reversed==n) || (reversed/10==n);
    }
};
