class Solution {
public:
    void solve(string& digits,int index,string output,vector<string> &ans,string mapp[]){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        
        int val = digits[index] - '0';
        string s = mapp[val];
        for(int i=0;i<s.length();i++){
            output.push_back(s[i]);
            solve(digits,index+1,output,ans,mapp);
            output.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string output;
        string mapp[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,0,output,ans,mapp);
        return ans;
    }
};