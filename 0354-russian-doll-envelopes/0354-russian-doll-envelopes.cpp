


class Solution {
public:
    
    static int cmp(vector<int> &a,vector<int> &b){
        if(a.front() > b.front()){
            return a.front() < b.front();
        }
        else{
            if(a.front() < b.front()){
                return a.front() < b.front();
            }
            else{
                return a.back() > b.back();
            }
        }
        
        //         if(a.front() == b.front())
        //             return a.back() > b.back();

        //         return a.front() < b.front();
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        // for(auto i: envelopes){
        //     for(auto j: i){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        
        vector<int> a;

        for(auto i: envelopes){
            a.push_back(i[1]);
        }
        
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i = 1; i<a.size(); i++){
            if(a[i] > ans.back()){
                ans.push_back(a[i]);
            }
            else{
                int index = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        
        return ans.size();
       
    }
    
    
};