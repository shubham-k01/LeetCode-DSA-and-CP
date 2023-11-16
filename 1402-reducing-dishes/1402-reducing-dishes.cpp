class Solution {
public:
    
    
    int solve(vector<int>& satisfaction,int& n, int index,int time){
        if(index >= n){
            return 0;
        }
        
        int include = satisfaction[index] * (time+1) + solve(satisfaction,n,index+1,time+1);
        int exclude = 0 + solve(satisfaction,n,index+1,time);
        
        return max(include,exclude);
    }
    
    int solveMem(vector<int>& satisfaction,int& n, int index,int time,vector<vector<int>> &dp){
        if(index >= n){
            return 0;
        }
        
        if(dp[index][time] != -1)
            return dp[index][time];
        
        int include = satisfaction[index] * (time+1) + solveMem(satisfaction,n,index+1,time+1,dp);
        int exclude = 0 + solveMem(satisfaction,n,index+1,time,dp);
        
        dp[index][time] = max(include,exclude);
        return dp[index][time];
    }
    
    int solveTab(vector<int>& satisfaction,int n){
        
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int currIndex = n-1; currIndex >=0 ; currIndex--){
//             start currTime from currIndex because the currIndex will be the total time for that index
            for(int currTime = currIndex; currTime >= 0; currTime--){
                int include = satisfaction[currIndex] * (currTime+1) + dp[currIndex+1][currTime+1];
                int exclude = 0 + dp[currIndex+1][currTime];

                dp[currIndex][currTime] = max(include,exclude);
            }
        }
        
        return dp[0][0];
    }
    
    int solveSpOp(vector<int>& satisfaction,int n){
        
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        
        for(int currIndex = n-1; currIndex >=0 ; currIndex--){
//             start currTime from currIndex because the currIndex will be the total time for that index
            for(int currTime = currIndex; currTime >= 0; currTime--){
                int include = satisfaction[currIndex] * (currTime+1) + next[currTime+1];
                int exclude = 0 + next[currTime];

                curr[currTime] = max(include,exclude);
            }
            next = curr;
        }
        
        return next[0];
    }
    
    
    
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        // return solve(satisfaction,n,0,0);
        
        // vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        // return solveMem(satisfaction,n,0,0,dp);
        
        // return solveTab(satisfaction,n);
        
        return solveSpOp(satisfaction,n);
    }
};