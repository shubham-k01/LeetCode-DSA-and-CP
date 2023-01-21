class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // for(int i = 0; i<nums.size();i++){
        //     nums[i] = nums[i]*nums[i];
        // }
        // sort(nums.begin(),nums.end());
        // return nums;
        
        int lo = 0,hi =nums.size()-1;
        vector<int> ans(nums.size());
        int k = nums.size()-1;
        
        while(lo<=hi){
            int max = abs(nums[lo])>nums[hi]?nums[lo]:nums[hi];
            if(max==nums[lo]){
                lo++;
            }
            else{
                hi--;
            }
            ans[k] = max*max;
            k--;
        }
        return ans;
    }
};