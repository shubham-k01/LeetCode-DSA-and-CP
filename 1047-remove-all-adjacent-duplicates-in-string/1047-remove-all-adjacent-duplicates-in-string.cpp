class Solution {
public:
    string removeDuplicates(string s){
        // int i=0;
        // while(i<s.size()){
        //     if(s[i]==s[i+1]){
        //         s.erase(i,2);
        //         i=0;
        //     }
        //     else{
        //         i++;
        //     }
        // }
        // return s;
        
        
        string st;
        int i=0;
        while(i<s.length()){
            if(!st.empty()){
                if(st.back()==s[i]){
                    st.pop_back();
                    // s.erase(i,1);
                }
                else{
                    st.push_back(s[i]);
                }
            }
            else{
                st.push_back(s[i]);
            }
            i++;
        }
        // cout << st.top();
        // string x = "";
        // while(!st.empty()){
        //     x = x + st.top();
        //     st.pop();
        // }
        // reverse(x.begin(),x.end());
        return st;
    }
};