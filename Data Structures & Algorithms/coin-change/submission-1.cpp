class Solution {
public:
    int noofCoins(int ind,int amount,vector<int>& coins,vector<vector<int>> &dp){
        if(ind<0){
            return 0;
        }
        if(ind==0){
            if(amount%coins[ind]==0){
                return amount/coins[ind];
            }
            if(amount==0){
                return 0;
            }
            return -1;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int nottake=noofCoins(ind-1,amount,coins,dp);
        int take=INT_MAX;
        if(amount>=coins[ind]){
            take=1+noofCoins(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=min(nottake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty()){
            return -1;
        }
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return noofCoins(n-1,amount,coins,dp);
    }

};
