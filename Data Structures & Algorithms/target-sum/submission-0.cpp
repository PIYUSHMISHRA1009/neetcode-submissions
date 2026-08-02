class Solution {
public:
    int TargetSum(int ind,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(ind<0){
            return false;
        }
        if(ind==0){
            if(nums[ind]==target){
                return true;
            }
            return false;
        }
        if(target==0){
            return 1;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int pick=TargetSum(ind-1,target-nums[ind],nums,dp);
        int notpick=TargetSum(ind-1,target,nums,dp);
        return dp[ind][target]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return TargetSum(n-1,target,nums,dp);
    }
};
