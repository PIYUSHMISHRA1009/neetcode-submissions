class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // optimal approach
        vector<int> res;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            if(mpp.find(complement)!=mpp.end()){
                int second=mpp[complement];
                if(i<second){
                    res.push_back(i);
                    res.push_back(second);
                }
                else{
                    res.push_back(second);
                    res.push_back(i);
                }
            }
            mpp[nums[i]]=i;
        }
        return res;
    }
};
