class Solution {
public:
    bool matches(char a,char b){
        if((a == '(' && b==')' )|| (a == '{' && b=='}' ) || (a == '[' && b==']' ) ){
            return true;
        }
        return false;
    }
    
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i]=='{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    char ch = st.top();
                    if(!matches(ch,s[i])){
                        return false;
                    }
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};