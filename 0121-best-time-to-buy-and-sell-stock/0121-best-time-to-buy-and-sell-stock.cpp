class Solution {
public:
    int maxProfit(vector<int>& prices) {
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