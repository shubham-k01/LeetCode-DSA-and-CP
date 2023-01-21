class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //   long lo=0,hi=nums.size()-1;
        //   while(lo<=hi){
        //       if(abs(nums[lo])>nums[hi]){
        //           swap(nums[lo],nums[hi]);
        //       }
        //           hi--;
        //   }
        //   swap(nums[0],nums[1]);
        //   for(int i=0;i<nums.size();i++){
        //       nums[i] = nums[i]*nums[i];
        //   }
        //   return nums;
        for(int i=0;i<nums.size();i++){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};