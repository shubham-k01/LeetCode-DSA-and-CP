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
    
    int solve2(vector<int> &cost,int &n){
        
        vector<int> dp(n+1,-1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        
        for(int i = 2;i<n;i++){
            
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
    
    int solve3(vector<int> &cost,int &n){
        
        int prev2 = cost[0];
        int prev1 = cost[1];
        int curr;
        
        
        for(int i = 2;i<n;i++){
            
            curr = cost[i] + min(prev1,prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1,prev2);
    }
    
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        
        int n = cost.size();
        vector<int> dp(n+1,-1);
        // return min(solve1(cost,n-1,dp),solve1(cost,n-2,dp));
        // return min(solve1(cost,0,dp),solve1(cost,1,dp));
        // return solve2(cost,n);
        return solve3(cost,n);
    }
    
};