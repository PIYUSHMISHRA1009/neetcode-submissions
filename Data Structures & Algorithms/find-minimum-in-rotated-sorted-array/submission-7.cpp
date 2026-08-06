class Solution {
public:
    int findMin(vector<int> &nums) {
        int low=0;
        int high=nums.size()-1;
        int mini=INT_MAX;
        while(low<high){
            int mid=(low+high)/2;
            mini=min(mini,nums[low]);
            if(nums[low]<=nums[mid]){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return nums[low];
    }
};
