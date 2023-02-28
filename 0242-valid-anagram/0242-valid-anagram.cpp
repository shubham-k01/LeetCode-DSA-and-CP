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
        
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int ct1[26]={0};
        int ct2[26]={0};
        for(int i=0;i<s.size();i++){
            int temp = s[i]-'a';
            ct1[temp]++;
            
            temp = t[i]-'a';
            ct2[temp]++;
        }
        
        if(isSame(ct1,ct2)){
            return true;
        }
        return false;
    }
};