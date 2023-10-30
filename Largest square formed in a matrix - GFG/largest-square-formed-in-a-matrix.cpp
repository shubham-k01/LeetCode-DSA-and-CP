//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(vector<vector<int>>& mat,int i,int j,int& maxi){
        
        if(i >= mat.size() || j>=mat[0].size()){
            return 0;
        }
        
        int right = solve(mat,i,j+1,maxi);
        int diagonal = solve(mat,i+1,j+1,maxi);
        int down = solve(mat,i+1,j,maxi);
    
        if(mat[i][j] == 1) {
            int ans = min(right,min(diagonal,down)) + 1;
            maxi = max(maxi,ans);
            return ans;
        }
        else{
            return 0;
        }
    }
    
    int solveMem(vector<vector<int>>& mat,int i,int j,int& maxi,vector<vector<int>>& dp){
        
        if(i >= mat.size() || j>=mat[0].size()){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = solve(mat,i,j+1,maxi);
        int diagonal = solve(mat,i+1,j+1,maxi);
        int down = solve(mat,i+1,j,maxi);
    
        if(mat[i][j] == 1) {
            dp[i][j] = min(right,min(diagonal,down)) + 1;
            maxi = max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return 0;
        }
    }
    
    int solveTab(vector<vector<int>>& mat,int &n,int &m,int& maxi){
        
        // making a mtrix of n+1 rows and m+1 columns becuase we need n row and m col in the dp
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
        for(int i = n-1; i>= 0 ; i--){
            for(int j = m-1; j>=0; j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
            
                if(mat[i][j] == 1) {
                    dp[i][j] = min(right,min(diagonal,down)) + 1;
                    maxi = max(maxi,dp[i][j]);
                }
            }
        }
        return maxi;
    }

    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // int maxi = 0;
        // solve(mat,0,0,maxi);
        // return maxi;
        
        // int maxi = 0;
        // vector<vector<int>> dp(n,vector<int> (m,-1));
        // solveMem(mat,0,0,maxi,dp);
        // return maxi;
        
        int maxi = 0;
        solveTab(mat,n,m,maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends