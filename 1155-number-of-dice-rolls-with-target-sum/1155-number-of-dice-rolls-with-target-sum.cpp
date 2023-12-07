class Solution {
    
public:
    const int MOD = 1e9+7;
    int solve(int n,int k, int target){
        // we have found one solution
        if(n == 0 && target == 0){
            return 1;
        }
        if(n != 0 && target == 0){
            return 0;
        }
        if(n == 0 && target != 0){
            return 0;
        }
        
        int ans = 0;
        for(int i = 1; i<=k; i++){
            ans = ans + solve(n-1,k,target-i);
        }
        return ans%MOD;
    }
    
    int solveMem(int n,int k, int target,vector<vector<long long>> &dp){
        // we have found one solution
        if(n == 0 && target == 0){
            return 1;
        }
        if(n != 0 && target == 0){
            return 0;
        }
        if(n == 0 && target != 0){
            return 0;
        }
        
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        
        long long ans = 0;
        for(int i = 1; i<=k; i++){
            if(target-i >= 0){
                ans = ans + solveMem(n-1,k,target-i,dp);
            }   
        }
        dp[n][target] = ans%MOD;
        
        return dp[n][target];
    }
    
    int numRollsToTarget(int n, int k, int target) {
        // return solve(n,k,target);
        
        vector<vector<long long>> dp(n+1,vector<long long> (target+1,-1));
        return solveMem(n,k,target,dp);
    }
};