class Solution {
public:
    
    int solve(vector<int> &nums,int n,int curr, int prev){
        if(curr >= n){
            return 0;
        }
        
        int include;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solve(nums,n,curr+1,curr);
        }
        
        int exclude = 0 + solve(nums,n,curr+1,prev);
        
        return max(include,exclude);
    }
    
    int solveMem(vector<int> &nums,int curr, int prev,vector<vector<int>> &dp){
        if(curr >= nums.size()){
            return 0;
        }
        
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveMem(nums,curr+1,curr,dp);
        }
        
        int exclude = solveMem(nums,curr+1,prev,dp);
        
        dp[curr][prev+1] = max(include,exclude);
        return dp[curr][prev+1];
    }
    
    int topDown(vector<int>& nums,int curr,int prev,vector<vector<int>>& dp){
         if(curr>=nums.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1)
            return dp[curr][prev+1];
        
        int include=0;
        if(prev==-1||nums[curr]>nums[prev])
            include=1+topDown(nums,curr+1,curr,dp);
        
        //exclude
        int exclude=topDown(nums,curr+1,prev,dp);
        dp[curr][prev+1]= max(include,exclude);
        return dp[curr][prev+1];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // return solve(nums,n,0,-1);
        
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solveMem(nums,0,-1,dp);
        
        // return topDown(nums,0,-1,dp);
    }
};