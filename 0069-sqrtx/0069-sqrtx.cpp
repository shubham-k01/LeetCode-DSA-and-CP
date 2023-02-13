class Solution {
public:
    long long int sqrtInt(int x){
        int s = 0;
        int e = x;
        long long int mid,ans;
        while(s<=e){
            mid = s + (e-s)/2;
            if(mid*mid==x){
                return mid;
            }
            if(mid*mid<x){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
    int mySqrt(int x) {
        return sqrtInt(x);
    }
};