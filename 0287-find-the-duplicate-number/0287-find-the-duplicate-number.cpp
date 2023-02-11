class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//         int a=nums[0];
//         for(int i=1;i<nums.size();i++){
//             a =(a ^ nums[i]);
//         }
//         for(int i=1;i<nums.size();i++){
//             a = (a ^ i);
//         }
//         unordered_map<int,int> mp;
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]++;
//         }
//         for(auto pr:mp){
//             if(pr.second > 1){
//                 return pr.first;
//             }
//         }
//         return -1;
        
//     }
        int pele=nums[0];
        int n=nums.size();
        vector <int> vec(n);
        for (int i=0;i<n;i++){
            vec[nums[i]]++;
        }
        for (int i=0;i<n;i++){
            if(vec[i]>1){
                pele=i;
                break;
            }
        }
        return pele;
    
};
};