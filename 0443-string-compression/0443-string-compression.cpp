class Solution {
public:
    int compress(vector<char>& chars) {
        int currentPos = 0;
        int i=0;
        if(chars.size()==0 || chars.size()==1){
            return chars.size();
        }
        while(i<chars.size()){
            int j = i+1;
            while(j<chars.size() && chars[i]==chars[j]){
                j++;
            }
            int ct = j-i;
            chars[currentPos++]=chars[i];
            if(ct>1){
                string s = to_string(ct);
                for(auto ch:s){
                    chars[currentPos++]=ch;
                }
            }
            i=j;
        }
        return currentPos;
    }
};