#include <bits/stdc++.h>


class Solution {
public:
    
    int solve(vector<int> &nums,int n,int curr, int prev){
        if(curr >= n){
            return 0;
        }
        
        int include = 0;
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
    
    int solveTab(vector<int> &nums){
        
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr; prev>= -1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + dp[curr+1][curr+1];
                }

                int exclude = dp[curr+1][prev+1];

                dp[curr][prev+1] = max(include,exclude);
            }
        }
        return dp[0][0];
    }
    
    int solveSpOp(vector<int> &nums){
        
        int n = nums.size();
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr; prev>= -1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + nextRow[curr+1];
                }

                int exclude = nextRow[prev+1];

                currRow[prev+1] = max(include,exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    
    int solveOptimal(vector<int> &nums){
        if(nums.size() == 0){
            return 0;
        }
        
        vector<int> ans;
        ans.push_back(nums[0]);
        
        for(int i = 1; i< nums.size(); i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index] = nums[i];
                
            }
        }
        
        return ans.size();
        
    }
    
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // return solve(nums,n,0,-1);
        
        // vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        // return solveMem(nums,0,-1,dp);
        
        // return solveTab(nums);
        
        // return solveSpOp(nums);
        
        return solveOptimal(nums);
    }
};