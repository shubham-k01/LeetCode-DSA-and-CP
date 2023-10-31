class Solution {
public:
    
    int solve(vector<int>& v,int i,int j){
        // if(v.size() == 2)
        if(i+1 == j){
            return 0;
        }
        
        int ans = INT_MAX;
        for(int k = i+1; k<j; k++){
            ans = min(ans,v[i]*v[j]*v[k] + solve(v,i,k) + solve(v,k,j));
        }
        return ans;
    }
    
    int solveMem(vector<int>& v,int i,int j,vector<vector<int>>& dp){
        // if(v.size() == 2)
        if(i+1 == j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        for(int k = i+1; k<j; k++){
            ans = min(ans,v[i]*v[j]*v[k] + solveMem(v,i,k,dp) + solveMem(v,k,j,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    
    int minScoreTriangulation(vector<int>& values) {
        // return solve(values,0,values.size()-1);
        
        int n = values.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solveMem(values,0,n-1,dp);
    }
};