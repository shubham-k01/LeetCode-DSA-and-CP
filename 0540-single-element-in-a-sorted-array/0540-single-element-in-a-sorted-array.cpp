class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int ans = nums[0];
        // for(int i=1;i<nums.size();i++){
        //     ans = ans^nums[i];
        // }
        // return ans;
        int lo=0,hi=nums.size()-1;
        int mid;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(mid%2){
                mid--;
            }
            if(nums[mid]!=nums[mid+1]){
                hi=mid;
            }
            else{
                lo+=2;
            }
        }
        return nums[lo];
    }
};