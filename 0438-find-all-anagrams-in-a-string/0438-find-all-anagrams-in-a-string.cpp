class Solution {
public:
    bool isSame(int ct1[],int ct2[]){
        for(int i=0;i<26;i++){
            if(ct1[i]!=ct2[i]){
                return false;
            }
        }
        return true;
    }
        
    vector<int> findAnagrams(string s1, string s2) {
        if(s2.size()>s1.size()) return {};
        int ct1[26]= {0};
        vector<int> a;
        for(int i=0;i<s2.size();i++){
            int idx = s2[i] - 'a';
            ct1[idx]++;
        }
        
        int ct2[26]={0};
        int i=0;
        int windowSize = s2.size();
        
        
        while(i<windowSize){
            int temp = s1[i] - 'a';
            ct2[temp]++;
            i++;
        }
        
        if(isSame(ct1,ct2)){
            a.push_back(i-windowSize);
        }
        
        while(i<s1.size()){
            int temp = s1[i] - 'a';
            ct2[temp]++;
            
            
            int old = s1[i-windowSize]-'a';
            ct2[old]--;
            
            if(isSame(ct1,ct2)){
                a.push_back(i-windowSize+1);
            }
            i++;
        }
        return a;
    }
};