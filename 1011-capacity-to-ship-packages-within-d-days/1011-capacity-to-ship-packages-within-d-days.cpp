class Solution {
public:
    bool isSolvable(vector<int> nums,int mid,int days){
        int tempd = 1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                tempd++;
                if(tempd<=days && nums[i]<=mid){
                    sum = nums[i];
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = 0;
        int hi = accumulate(weights.begin(),weights.end(),0);
        int mid,ans;
        while(lo<=hi){
            mid = lo +(hi-lo)/2;
            if(isSolvable(weights,mid,days)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};