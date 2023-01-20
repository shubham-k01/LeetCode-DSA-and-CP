class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo=0,hi=arr.size()-1;
        int mid;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(arr[mid]<arr[mid+1]){
                lo = mid+1;
            }
            // else if(arr[mid]>arr[mid]+1){
            //     hi=mid-1;
            // }
            else{
                hi = mid;
            }
        }
        return hi;
    }
};