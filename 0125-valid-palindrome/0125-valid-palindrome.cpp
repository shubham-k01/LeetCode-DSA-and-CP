class Solution {
public:
    bool isAlphaNum(char a){
        if(a>='A' && a<='Z' || a>='a' && a<='z' || a>='0' && a<='9'){
            return true;
        }
        return false;
    }

    char lowerCase(char a){
        if(a>='A' && a<='Z'){
            a = a-'A';
            a=a+'a';
            return a;
        }
        else{
            return a;
        }
    }

    bool isPalindrome(string s) {
        int st = 0;
        int e = s.length()-1;
        while(st<e){
            if(isAlphaNum(s[st]) && isAlphaNum(s[e])){
                if(lowerCase(s[st])==lowerCase(s[e])){
                    st++;
                    e--;
                }
                else{
                    return false;
                }
            }
            else{
                if(!isAlphaNum(s[st])){
                    st++;
                }
                if(!isAlphaNum(s[e])){
                    e--;
                }
            }
        }
        return true;
    }
};