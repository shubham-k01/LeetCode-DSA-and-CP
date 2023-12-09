class Solution {
public:
    
    int solve(vector<int> &nums1, vector<int> &nums2,int n,int index,bool swapped){
        if(index >= n){
            return 0;
        }
        
        int ans = INT_MAX;
        
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        
        // swapping previous values if needed before comparing for the current index
        if(swapped){
            swap(prev1,prev2);
        }
        
        // noswap
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solve(nums1,nums2,n,index+1,0);
        }
        
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans, 1 + solve(nums1,nums2,n,index+1,1));
        }
        
        return ans;
    }
    
    int solveMem(vector<int> &nums1, vector<int> &nums2,int n,int index,bool swapped,vector<vector<int>> &dp){
        if(index == n){
            return 0;
        }
        
        if(dp[index][swapped] != -1)
            return dp[index][swapped];
        
        int ans = INT_MAX;
        
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        
        // swapping previous values if needed before comparing for the current index
        if(swapped){
            swap(prev1,prev2);
        }
        
        // noswap
        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = solveMem(nums1,nums2,n,index+1,0,dp);
        }
        
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans, 1 + solveMem(nums1,nums2,n,index+1,1,dp));
        }
        
        return dp[index][swapped] = ans;
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        
        int n = nums1.size();
        bool swapped = 0;
        // return solve(nums1,nums2,n,1,swapped);
        
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return solveMem(nums1,nums2,n,1,swapped,dp);
    }
};