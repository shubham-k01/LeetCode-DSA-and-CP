class Solution {
public:
    
    
    int solve(vector<int>& satisfaction,int& n, int index,int time){
        if(index >= n){
            return 0;
        }
        
        int include = satisfaction[index] * (time) + solve(satisfaction,n,index+1,time+1);
        int exclude = 0 + solve(satisfaction,n,index+1,time);
        
        return max(include,exclude);
    }
    
    int solveMem(vector<int>& satisfaction,int& n, int index,int time,vector<vector<int>> &dp){
        if(index >= n){
            return 0;
        }
        
        if(dp[index][time] != -1)
            return dp[index][time];
        
        int include = satisfaction[index] * (time) + solveMem(satisfaction,n,index+1,time+1,dp);
        int exclude = 0 + solveMem(satisfaction,n,index+1,time,dp);
        
        dp[index][time] = max(include,exclude);
        return dp[index][time];
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        // return solve(satisfaction,n,0,1);
        
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solveMem(satisfaction,n,0,1,dp);
    }
};