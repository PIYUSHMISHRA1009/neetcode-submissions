class Solution {
public:
   int SubsetSum(int ind,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(ind<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(ind==0){
            if (target == 0 && nums[0] == 0)
                return 2;

            if (target == 0 || target == nums[0])
                return 1;

            return 0;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int notpick=SubsetSum(ind-1,target,nums,dp);
        int pick=0;
        if(target>=nums[ind]){
            pick=SubsetSum(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //use formula subset1-subset2=target
        int n=nums.size();
        int totSum=0;
        for(auto it:nums){
            totSum+=it;
        }
        if(totSum-target<0 || (totSum-target)%2!=0) return 0;
        int s1=(totSum-target)/2;
        vector<vector<int>> dp(n,vector<int>(s1+1,-1));
        return SubsetSum(n-1,s1,nums,dp);
    }
};
