class Solution {
public:
    bool SubsetSum(int ind,int target,vector<int> &nums,vector<vector<bool>> &dp){
        if(ind<0){
            return false;
        }
        if(target==0){
            return true;
        }
        if(ind==0){
            return nums[0]==target;
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
        vector<vector<bool>> dp(nums.size(),vector<bool>(target+1,false));
        bool PartitionSet=SubsetSum(nums.size()-1,target,nums,dp);
        return PartitionSet;

    }
};
