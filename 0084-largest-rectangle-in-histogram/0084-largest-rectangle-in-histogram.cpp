class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(arr.size(),-1);

        for(int i = arr.size()-1 ; i >=0 ; i--){
            int t = arr[i];
            while(st.top()!=-1 && arr[st.top()] >= t){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);

        }

        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> &arr, int n)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(arr.size(),-1);

        for(int i = 0 ; i <n ; i++){
            int t = arr[i];
            while(st.top()!=-1 && arr[st.top()] >= t){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);

        }

        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next(heights.size());
        next = nextSmallerElement(heights,heights.size());

        vector<int> prev(heights.size());
        prev =prevSmallerElement(heights,heights.size());
        
        int area = INT_MIN;
        for(int i=0;i<heights.size();i++){
            int l = heights[i];
            
            if(next[i]==-1){
                next[i] = heights.size();
            }
            int b = next[i] - prev[i] - 1 ;
            
            int newArea = l*b;
            area = max(area,newArea);
        }
        
        return area;
        
    }
};