//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    void lowerCase(char x){
        if(x='A' && x<='Z'){
            x = x -'A';
            x = x + 'a';
        }
    }
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        vector<int> a(26);
        // char x;
        for(int i=0;i<str.size();i++){
            int in = str[i] -'a';
            a[in]++;
        }
        
        int ma= INT_MIN,ans=0;
        for(int i=0;i<26;i++){
            if(a[i]>ma){
                ma = a[i];
                ans=i;
            }
        }
        return ans +'a';
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends