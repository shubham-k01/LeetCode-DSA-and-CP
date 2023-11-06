class Solution {
public:
    
    int solve(vector<int>& obstacles,int currpos, int currlane){
        if(currpos == obstacles.size() - 1){
            return 0;
        }
        
        if(obstacles[currpos+1] != currlane){
            return solve(obstacles,currpos+1,currlane);
        }
        
        int ans = INT_MAX;
        for(int j = 1; j<=3; j++){
            if(currlane != j  && obstacles[currpos] != j){
                ans = min(ans, 1 + solve(obstacles,currpos,j));
            }
        }
        
        
        return ans;
        
    }
    
    int solveMem(vector<int>& obstacles,int currpos, int currlane,vector<vector<int>> &dp ){
        if(currpos == obstacles.size() - 1){
            return 0;
        }
        
        if(dp[currlane][currpos] != -1){
            return dp[currlane][currpos];
        }
        
        if(obstacles[currpos+1] != currlane){
            return solveMem(obstacles,currpos+1,currlane,dp);
        }
        
        int ans = INT_MAX;
        for(int j = 1; j<=3; j++){
            if(currlane != j  && obstacles[currpos] != j){
                ans = min(ans, 1 + solveMem(obstacles,currpos,j,dp));
            }
        }
        
        dp[currlane][currpos] = ans;
        
        
        return dp[currlane][currpos];
        
    }
    
    int solveTab(vector<int>& obstacles,int currpos, int currlane,vector<vector<int>> &dp ){
        if(currpos == obstacles.size() - 1){
            return 0;
        }
        
        if(dp[currlane][currpos] != -1){
            return dp[currlane][currpos];
        }
        
        if(obstacles[currpos+1] != currlane){
            return solve(obstacles,currpos+1,currlane);
        }
        
        int ans = INT_MAX;
        for(int j = 1; j<=3; j++){
            if(currlane != j  && obstacles[currpos] != j){
                ans = min(ans, 1 + solveMem(obstacles,currpos,j,dp));
            }
        }
        
        dp[currlane][currpos] = ans;
        
        
        return dp[currlane][currpos];
        
    }
    
    
    int minSideJumps(vector<int>& obstacles) {
        
        // return solve(obstacles,0,2);
        
        int n = obstacles.size();
        vector<vector<int>> dp(4,vector<int> (n,-1));
        return solveMem(obstacles,0,2,dp);
    }
};