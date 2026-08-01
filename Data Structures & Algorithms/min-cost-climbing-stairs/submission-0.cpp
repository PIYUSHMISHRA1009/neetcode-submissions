class Solution {
public:
    int costOfclimbingStairs(int n,vector<int> &cost,vector<int> &dp){
        if(n<0){
            return 0;
        }
        if(n==0 || n==1){
            return cost[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int mincost=cost[n];
        mincost+=min(costOfclimbingStairs(n-1,cost,dp),costOfclimbingStairs(n-2,cost,dp));
        return dp[n]=mincost;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        int mincost=costOfclimbingStairs(n-1,cost,dp);
        int mincost2=costOfclimbingStairs(n-2,cost,dp);
        return min(mincost,mincost2);
    }   
};
