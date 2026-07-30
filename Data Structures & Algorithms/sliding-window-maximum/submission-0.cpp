class Solution {
public:
    int findmax(vector<int> &nums,int low,int high){
        int maxi=INT_MIN;
        for(int i=low;i<=high;i++){
            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int low=0;
        int high=k-1;
        int n=nums.size();
        while(high<n){
            int maxwind=findmax(nums,low,high);
            res.push_back(maxwind);
            low++;
            high++;
        }
        return res;
    }
};
