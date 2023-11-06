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
    
    int solveTab(vector<int>& obstacles){
        
        int n = obstacles.size() -1;
        vector<vector<int>> dp(4, vector<int> (n+1,1e9));
        
        //base case
        
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;
        
        for(int currpos = n-1; currpos>=0 ; currpos--){
            for(int currlane = 1; currlane<=3; currlane++){
                if(obstacles[currpos+1] != currlane){
                    dp[currlane][currpos] =  dp[currlane][currpos+1];
                }

                else{
                    int ans = 1e9;
                    for(int k = 1; k<=3; k++){
                        if(currlane != k  && obstacles[currpos] != k){
                            ans = min(ans, 1 + dp[k][currpos+1]);
                        }
                    }  
                    dp[currlane][currpos] = ans;
                }
            }
            
        }
        
        return min(dp[2][0],min(dp[2][0] + 1,dp[3][0] + 1));

    }
    
    
    int minSideJumps(vector<int>& obstacles) {
        
        // return solve(obstacles,0,2);
        
        // int n = obstacles.size();
        // vector<vector<int>> dp(4,vector<int> (n,-1));
        // return solveMem(obstacles,0,2,dp);
        
        return solveTab(obstacles);
    }
};