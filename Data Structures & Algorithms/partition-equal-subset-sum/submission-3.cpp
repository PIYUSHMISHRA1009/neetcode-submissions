class Solution {
public:
    bool SubsetSum(int ind,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(ind<0){
            return false;
        }
        if(target==0){
            return true;
        }
        if(ind==0){
            return nums[0]==target;
        }
        if(dp[ind][target]){
            return dp[ind][target];
        }
        bool notpick=SubsetSum(ind-1,target,nums,dp);
        bool pick=false;
        if(target>=nums[ind]){
            pick=SubsetSum(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=pick||notpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        bool PartitionSet=SubsetSum(nums.size()-1,target,nums,dp);
        return PartitionSet;

    }
};
