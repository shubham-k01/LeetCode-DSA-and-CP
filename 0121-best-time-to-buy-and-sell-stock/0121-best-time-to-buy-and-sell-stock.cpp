class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int maxe = 0;
        // int n = prices.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(prices[j]>prices[i]){
        //             if(prices[j]-prices[i]>maxe){
        //                 maxe = prices[j]-prices[i];
        //             }
        //         }
        //     }
        // }
        // return maxe;


        int mine = INT_MAX;
        int maxe = 0;

        for(int i=0;i<prices.size();i++){
            if(prices[i]<mine){
                mine=prices[i];
            }
            if(prices[i]-mine>maxe){
                maxe = prices[i]-mine;
            }
        }
        return maxe;
    }
};