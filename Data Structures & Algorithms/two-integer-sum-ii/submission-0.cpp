class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        vector<int> res;
        while(l<r){
             if(nums[l]+nums[r]<target){
                l++;
             }
             else if(nums[l]+nums[r]>target){
                r--;
             }
             else{
                res.push_back(l+1);
                res.push_back(r+1);
                l++;
                r--;
                break;
             }
        }
        return res;
    }
};
