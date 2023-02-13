class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> a;
        vector<int> temp;
        if(intervals.size()==0 || intervals.size()==1) return intervals;
        
        if(intervals[0][1]>=intervals[1][0]){
            temp = {intervals[0][0],max(intervals[0][1],intervals[1][1])};
            a.push_back(temp);
        }
        else{
            a.push_back(intervals[0]);
            a.push_back(intervals[1]);
        }
        auto it = --a.end();
        int i=2;
        while(i<intervals.size()){
            if((*it)[1]>=intervals[i][0]){
                temp = {(*it)[0],max((*it)[1],intervals[i][1])};
                a.pop_back();
                a.push_back(temp);
            }
            else{
                a.push_back(intervals[i]);
            }
            it = --a.end();
            i++;
        }
        return a;
    }
};