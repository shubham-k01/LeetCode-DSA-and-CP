class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int max=INT_MIN,curr_max=0;
        int n = arr.size();
        for(int i=0;i<n;i++){

            if(arr[i]<=curr_max+arr[i]){
                curr_max = curr_max+arr[i];
            }
            else{
                curr_max = arr[i];
            }

            if(max<curr_max){
                max = curr_max;
            }
        }
        return max;
    }
};