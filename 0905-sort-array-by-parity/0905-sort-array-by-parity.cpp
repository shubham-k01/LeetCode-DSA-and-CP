class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i,j;
        i=0;j=nums.size()-1;
        while(i<j){
            if(nums[i]%2==1 && nums[j]%2==0){
                swap(nums[i++],nums[j--]);
            }
            else if(nums[i]%2==1 && nums[j]%2==1){
                j--;
            }
            else if(nums[i]%2==0 && nums[j]%2==0){
                i++;
            }
            else{
                i++;j--;
            }
        }
        return nums;
    }
};