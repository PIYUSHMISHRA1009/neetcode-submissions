class Solution {
public:
    //start the recursion from last index and last index-1 ..
    //you will get the answer
    int HouseRobber(int n,vector<int> &nums,vector<int> &dp){
        if(n<0){
            return 0;
        }
        if(n==0 || n==1){
            return nums[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int cost=nums[n];
        cost+=HouseRobber(n-2,nums,dp);
        return dp[n]=cost;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int lastindex=HouseRobber(n-1,nums,dp);
        int slastindex=HouseRobber(n-2,nums,dp);
        return max(lastindex,slastindex);
    }
};
