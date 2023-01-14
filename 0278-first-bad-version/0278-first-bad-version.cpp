// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int mid;
        int l=1;
        int h=n;
        if(n==1){
            return 1;
        }
        while(l<=h){
            mid=l+(h-l)/2;
            if(isBadVersion(mid)){
                h=mid-1;
            }
            else{
               l=mid+1;
            }
        }
        return l;
    }
};