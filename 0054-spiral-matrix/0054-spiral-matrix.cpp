class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int lastRow = matrix.size()-1;
        int lastColumn = matrix[0].size()-1;
        int firstRow = 0;
        int firstColumn = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        int count = 0;
        vector<int> ans;
        
        while(count<(n*m)){
            for(int i=firstColumn;i<=lastColumn && count<(n*m);i++){
                ans.push_back(matrix[firstRow][i]);
                count++;
            }
            firstRow++;
            for(int i=firstRow;i<=lastRow && count<(n*m);i++){
                ans.push_back(matrix[i][lastColumn]);
                count++;
            }
            lastColumn--;
            for(int i=lastColumn;i>=firstColumn && count<(n*m);i--){
                ans.push_back(matrix[lastRow][i]);
                count++;
            }
            lastRow--;
            for(int i=lastRow;i>=firstRow && count<(n*m);i--){
                ans.push_back(matrix[i][firstColumn]);
                count++;
            }
            firstColumn++; 
        }
        return ans;
    }
};