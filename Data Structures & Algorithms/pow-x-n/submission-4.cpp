class Solution {
public:
    double myPow(double x, int n) {
        
        long long N = n;
        if(N < 0){
            x = 1/x;
            N = -N;
        }

        double result = 1;
        while(N >0){
            // if(N % 2==1){
            //     result*=x; /// (2 * 2) * 2
            // }
            // x*=x; // 2 * 2
            // N=N/2;

            result = result * x;
            N--;
        }
        return result;
    }
};
