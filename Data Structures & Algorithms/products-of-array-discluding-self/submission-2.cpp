class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //prefix and suffix;
        int n=nums.size();
        vector<int> res(n,1);
        int prefix=1;
        for(int i=1;i<nums.size();i++){
            prefix=nums[i-1]*prefix;
            res[i]=prefix;
        }
        int suffix=1;
        for(int j=n-1;j>=0;j--){
            res[j]=res[j]*suffix;
            suffix=nums[j]*suffix;
        }
        return res;

    }
};
