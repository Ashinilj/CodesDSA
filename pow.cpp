class Solution {
public:
    double myPow(double x, int n) {
       if(n==0) return 1;
       else if(n==1) return x;

       long long N= n;
       if(N<0){
            x= 1/x;
            N= -N;
       }

       double half= pow(x, N/2);
       if(N%2==0) return half*half;
       else return half*half*x;
    }
};
