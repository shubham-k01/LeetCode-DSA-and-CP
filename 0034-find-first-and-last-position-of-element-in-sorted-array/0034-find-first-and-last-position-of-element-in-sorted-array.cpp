class Solution {
public:

    int firstOcc(vector<int>& nums,int target){
        int lo=0,hi=nums.size()-1;
        int mid,ans=-1;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid]==target){
                ans=mid;
               hi=mid-1; 
            }
            else if(nums[mid]>target){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
    int lastOcc(vector<int>& nums,int target){
        int lo=0,hi=nums.size()-1;
        int mid,ans=-1;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid]==target){
                ans=mid;
               lo=mid+1; 
            }
            else if(nums[mid]>target){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1,-1};
        }
        vector<int> p;
        p.push_back(firstOcc(nums,target));
        p.push_back(lastOcc(nums,target));
        return p;
    }
};