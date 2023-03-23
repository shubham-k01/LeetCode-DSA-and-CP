class Solution {
public:
    
//     bool isSame(int* a,int* b){
//         for(int i=0;i<26;i++){
//             if(a[i]!=b[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
//     string removeOccurrences(string s, string part) {
//         int wlen = part.length();
//         int i=0;
//         int countPart[26] = {0};
//         int countS[26] = {0};
//         while(i<wlen){
//             countPart[part[i]-'a']++;
//             i++;
//         }
        
//         i=0;
//         while(i<wlen){
//             countS[s[i]-'a']++;
//             i++;
//         }
//         if(isSame(countS,countPart)){
//             s.erase(0,wlen);
//         }
//         i=0;
//         while(i<s.length()){
//             countS[s[i++]-'a']++;
//             countS[s[i-wlen]-'a']--;
//             if(isSame(countS,countPart)){
//                 s.erase(i-wlen,wlen);
//                 i=0;
//             }
//         }
//         return s;
//     }
    void removePart(string &s,string part,int p){
        if(p==string::npos)
            return ;
        s.erase(p,part.length());
        int i = s.find(part);
        removePart(s,part,i);
    }
    string removeOccurrences(string s, string part) {
        int i = s.find(part);
        removePart(s,part,i);
        return s;
    }
};