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
        int pick=nums[n]+HouseRobber(n-2,nums,dp);
        int notpick=0+HouseRobber(n-1,nums,dp);
        return dp[n]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return HouseRobber(n-1,nums,dp);
    }
};
