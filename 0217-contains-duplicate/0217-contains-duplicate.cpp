class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]++;
            }
            else{
                return true;
            }
        }
        return false;
        // return nums.size() > set<int> (nums.begin(),nums.end()).size();
    }
};
        