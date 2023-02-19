//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        int current,lo,hi;
        sort(A,A+n);
        for(int i=0;i<n;i++){
            lo=i+1;hi=n-1;
            while(lo<hi){
                current = A[i]+A[lo]+A[hi];
                if(current==X){
                    return true;
                }
                if(current<X){
                    lo++;
                }
                else{
                    hi--;
                }
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends