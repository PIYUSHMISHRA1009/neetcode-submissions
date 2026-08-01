class Solution {
public:
    int HouseRobber(int ind,vector<int> &nums,vector<int> &dp){
        if(ind<0){
            return 0;
        }
        if(ind==0){
            return nums[0];
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick=nums[ind]+HouseRobber(ind-2,nums,dp);
        int notpick=0+HouseRobber(ind-1,nums,dp);
        return dp[ind]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        vector<int> nums1;
        vector<int> nums2;
        for(int i=0;i<nums.size();i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=nums.size()-1) nums2.push_back(nums[i]);
        }
        vector<int> dp1(nums1.size(),-1);
        vector<int> dp2(nums2.size(),-1);
        int res1=HouseRobber(nums1.size()-1,nums1,dp1);
        int res2=HouseRobber(nums2.size()-1,nums2,dp2);
        return max(res1,res2);
    }
};
