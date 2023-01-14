class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target && i!=j){
        //             a.push_back(i);
        //             a.push_back(j);
        //             break;
        //         }
        //     }
        // }
        
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i])!=m.end()){
                return {m[target-nums[i]],i};
            }
            else{
                m[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};