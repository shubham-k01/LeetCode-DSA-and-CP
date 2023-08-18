class Solution {
public:
    int solve(vector<int> &cost,int x,int &n){
        if(x >= n){
            return 0;
        }
        // if(x > n){
        //     return 0;
        // }
        
        return cost[x] + min(solve(cost,x+1,n),solve(cost,x+2,n));
    }
    
    
    
//     int solve1(vector<int> &cost,int x,vector<int> &dp){
//         if(x == 0){
//             return cost[0];
//         }
//         if(x==1){
//             return cost[1];
//         }
        
//         if(dp[x] != -1)
//             return dp[x];
        
//         dp[x] = cost[x] + min(solve1(cost,x-1,dp),solve1(cost,x-2,dp));
//         return dp[x];
//     }
    
    int solve1(vector<int> &cost,int x,vector<int> &dp){
        // if(x == 0){
        //     return cost[0];
        // }
        // if(x==1){
        //     return cost[1];
        // }
        
        if(x >= cost.size()){
            return 0;
        }
        
        if(dp[x] != -1)
            return dp[x];
        
        dp[x] = cost[x] + min(solve1(cost,x+1,dp),solve1(cost,x+2,dp));
        return dp[x];
    }
    
    int solve2(vector<int> &cost,int x,int &n){
        
        vector<int> dp(n+1,-1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        
        dp[x] = cost[x] + min(solve(cost,x+1,n),solve(cost,x+2,n));
        return dp[x];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        // return min(solve1(cost,n-1,dp),solve1(cost,n-2,dp));
        return min(solve1(cost,0,dp),solve1(cost,1,dp));
    }
    
};