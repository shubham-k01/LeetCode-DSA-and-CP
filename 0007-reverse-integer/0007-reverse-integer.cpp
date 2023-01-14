class Solution {
public:
    int reverse(int n) {
        long long d=0,r;
        while(n/10){
            d=d*10+n%10;
            n=n/10;
        }
        d=d*10+n%10;
        n=n/10;
        if(d>pow(2,31)-1 || d<-pow(2,31)){
            return 0;
        }
        return d;
    }
};