class Solution {
public:
    
    bool BS(vector<int> arr,int s,int e,int target){
        int mid ;
        while(s<=e){
            mid = s + (e-s)/2;
            if(arr[mid]==target){
                return true;
            }
            if(arr[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }    
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            vector<int> temp = matrix[i];
            if(temp[0]<=target && temp[temp.size()-1]>=target){
                return BS(temp,0,temp.size()-1,target);
            }
        }
        return false;
    }
};