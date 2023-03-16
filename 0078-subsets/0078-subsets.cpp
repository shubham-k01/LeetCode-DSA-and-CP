class Solution {
public:
    void solve(vector<int> &nums,int index,vector<int> output,vector<vector<int>> &ans){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }

        solve(nums,index+1,output,ans);

        int temp = nums[index];
        output.push_back(temp);
        solve(nums,index+1,output,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums,0,output,ans);
        return ans;
    }
};