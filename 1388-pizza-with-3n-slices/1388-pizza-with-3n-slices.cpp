class Solution {
public:
    
    int solve(vector<int> &slices, int endIndex, int n, int index ){
        if(n == 0 || index > endIndex){
            return 0;
        }
        
        int case1 = slices[index] + solve(slices,endIndex,n-1,index+2);
        int case2 = 0 + solve(slices,endIndex,n,index+1);
        
        return max(case1,case2);
    }
    
    int solveMem(vector<int> &slices, int endIndex, int n, int index, vector<vector<int>> &dp){
        if(n == 0 || index > endIndex){
            return 0;
        }
        
        if(dp[n][index] != -1){
            return dp[n][index];
        }
        
        int case1 = slices[index] + solveMem(slices,endIndex,n-1,index+2,dp);
        int case2 = 0 + solveMem(slices,endIndex,n,index+1,dp);
        
        return dp[n][index]  = max(case1,case2);
    }
    
    
    int solveTab(vector<int> &slices){
       
        int n = slices.size();
        vector<vector<int>> dp1(n+2,vector<int> (n+2,0));
        vector<vector<int>> dp2(n+2,vector<int> (n+2,0));
        
        for(int k = 1; k <= n/3; k++){
            for(int index = n-2; index >=0; index--){
                int case1 = slices[index] + dp1[k-1][index+2];
                int case2 = 0 + dp1[k][index+1];
                
                dp1[k][index] = max(case1,case2);
            }
        }
        
        int one = dp1[n/3][0];
        
        for(int k = 1; k <= n/3; k++){
            for(int index = n-1; index >=1; index--){
                int case1 = slices[index] + dp2[k-1][index+2];
                int case2 = 0 + dp2[k][index+1];
                
                dp2[k][index] = max(case1,case2);
            }
        }
        
        int two = dp2[n/3][1];
        
        return max(one,two);
        
        
    }
    
    int maxSizeSlices(vector<int>& slices) {
        
        int n = slices.size();
        // n/3 because pizza is of 3n slices so we will get to eat n slices
        // int case1 =  solve(slices,n-2,n/3,0);
        // int case2 = solve(slices,n-1,n/3,1);
        
        
        // vector<vector<int>> dp1(n+1,vector<int> (n+1,-1));
        // vector<vector<int>> dp2(n+1,vector<int> (n+1,-1));
        
        
        // int case1 = solveMem(slices,n-2,n/3,0,dp1);
        // int case2 = solveMem(slices,n-1,n/3,1,dp2);
        // return max(case1,case2);
        
        return solveTab(slices);
    }
};