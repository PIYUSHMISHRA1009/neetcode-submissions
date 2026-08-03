class Solution {
public:
    int noofCoins(int ind,int amount,vector<int>& coins,vector<vector<int>> &dp){
        if(ind==0){
            if(amount%coins[ind]==0){
                return 1;
            }
            return 0;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int nottake=noofCoins(ind-1,amount,coins,dp);
        int take=0;
        if(amount>=coins[ind]){
            take=noofCoins(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=nottake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=noofCoins(n-1,amount,coins,dp);
        return ans;
    }
};
