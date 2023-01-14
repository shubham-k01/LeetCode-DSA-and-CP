class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid;
        int l=0;
        int h=nums.size()-1;
        while(l<=h){
            mid=l+(h-l)/2;
            if(target==nums[mid]){
                return mid;
            }
            if(nums[mid]>target){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        int i;
        for(i=0;i<nums.size();i++){
            if(nums[i]>target){
                break;
            }
        }
        return i;
    }
};