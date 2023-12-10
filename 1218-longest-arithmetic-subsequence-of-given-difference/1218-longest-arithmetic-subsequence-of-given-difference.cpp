class Solution {
public:
    
    
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        
        unordered_map<int,int> dp;
        for(int i=0; i<arr.size(); i++){
            int diff = arr[i] - difference;
            int cnt = 1;
            
            if(dp.count(diff)){
                cnt += dp[diff];
            }

            dp[arr[i]] = cnt;
            ans = max(ans,cnt);
            
            
            
        }
        return ans;
    }
};