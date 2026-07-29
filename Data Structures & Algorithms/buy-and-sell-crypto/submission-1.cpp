class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //remember ..first buy then sell stock
        if(prices.empty()){
            return 0;
        }
        int minPrices=prices[0];
        int maxProfit=0;
        for(int i=1;i<prices.size();i++){
            int Profit=prices[i]-minPrices;
            maxProfit=max(maxProfit,Profit);
            minPrices=min(minPrices,prices[i]);
        }
        return maxProfit;
    }
};
