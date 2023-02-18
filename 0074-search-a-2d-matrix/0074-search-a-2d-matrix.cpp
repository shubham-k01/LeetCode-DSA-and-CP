class Solution {
public:
    
    // bool BS(vector<int> arr,int s,int e,int target){
    //     int mid ;
    //     while(s<=e){
    //         mid = s + (e-s)/2;
    //         if(arr[mid]==target){
    //             return true;
    //         }
    //         if(arr[mid]>target){
    //             e=mid-1;
    //         }
    //         else{
    //             s=mid+1;
    //         }
    //     }    
    //     return false;
    // }
    
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     for(int i=0;i<matrix.size();i++){
    //         vector<int> temp = matrix[i];
    //         if(temp[0]<=target && temp[temp.size()-1]>=target){
    //             return BS(temp,0,temp.size()-1,target);
    //         }
    //     }
    //     return false;
    // }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        
        int lo= 0;
        int hi = (row*column)-1;
        int mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(matrix[mid/column][mid%column]==target){
                return true;
            }
            if(matrix[mid/column][mid%column]>target){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return false;
    }
};