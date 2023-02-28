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
    
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int ct1[26]= {0};
        for(int i=0;i<s1.size();i++){
            int idx = s1[i] - 'a';
            ct1[idx]++;
        }
        
        int ct2[26]={0};
        int i=0;
        int windowSize = s1.size();
        
        
        while(i<windowSize){
            int temp = s2[i] - 'a';
            ct2[temp]++;
            i++;
        }
        
        if(isSame(ct1,ct2)){
            return true;
        }
        
        while(i<s2.size()){
            int temp = s2[i] - 'a';
            ct2[temp]++;
            
            
            int old = s2[i-windowSize]-'a';
            ct2[old]--;
            
            if(isSame(ct1,ct2)){
                return true;
            }
            i++;
        }
        return false;
        
        // for(int j=0;j<s2.size()-s1.size()-1;j++){
        //     for(int k=j;k<s1.size();k++){
        //         int idx = s2[k] - 'a';
        //         ct2[idx]++;
        //     }
        //     if(isSame(ct1,ct2)){
        //         return true;
        //     }
        //     ct2[s2[j]-'a']--;
        // }
        // return false;
    }
};