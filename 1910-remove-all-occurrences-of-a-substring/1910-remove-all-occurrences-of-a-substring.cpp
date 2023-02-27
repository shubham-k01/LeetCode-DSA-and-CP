class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()>0 && s.find(part)<s.length()){
            size_t found = s.find(part);
            if(found != string::npos){
                s.erase(found,part.length());
            }
            else{
                break;
            }
            
        }
        return s;
    }
};