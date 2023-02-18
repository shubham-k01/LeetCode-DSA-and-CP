class Solution {
public:
    
    int BS(vector<int> arr,int s,int e,int target){
        int mid ;
        while(s<=e){
            mid = s + (e-s)/2;
            if(arr[mid]==target){
                return mid;
            }
            if(arr[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }    
        return -1;
    }
    
    int getPivot(vector<int> arr,int n){
        int s = 0;
        int e =n-1;
        int mid;
        while(s<e){
            mid = s +(e-s)/2;
            if(arr[mid]>=arr[0]){
                s = mid+1;
            }
            else{
                e = mid;
            }
        }
        return e;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target){
                return 0;
            }
            return -1;
        }
        if(nums.size()==2){
            if(nums[0]==target){
                return 0;
            }
            else if(nums[1]==target){
                return 1;
            }
            return -1;
        }
        int pivot = getPivot(nums,nums.size());
        
        if(target>=nums[pivot] && target<=nums[nums.size()-1]){
            return BS(nums,pivot,nums.size()-1,target);
        }
        else{
            return BS(nums,0,pivot-1,target);
        }
    }
};