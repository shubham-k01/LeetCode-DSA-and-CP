class Solution {
public:
    int getPivot(vector<int> &nums){
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid;
        while(s<e){
            mid = s + (e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e = mid;
            }
        }
        return e;
    }
    int binarySearch(vector<int>& nums,int st,int end,int x){
        int s = st,e = end;
        long long mid;
        while(s<=e){
            mid =s +(e-s)/2;
            if(nums[mid]==x){
                return mid;
            }
            if(nums[mid]>x){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int s = 0,e = nums.size()-1;
        int pivot = getPivot(nums);
        // cout<<pivot<<endl;
        if(nums[pivot]<=target && target<=nums[e]){
            return binarySearch(nums,pivot,e,target);
        }else{
            return binarySearch(nums,0,pivot-1,target);
        }
        
        
        return -1;
    }
};