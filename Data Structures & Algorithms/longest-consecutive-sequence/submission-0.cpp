class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set<int> st;
        int n=nums.size();
        int longest=INT_MIN;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                cnt++;
                x=x+1;
            }
            longest=max(longest,cnt);
        }
        return longest;
    }
};
