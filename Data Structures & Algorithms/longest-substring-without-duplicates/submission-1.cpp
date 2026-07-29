class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        int high=0;
        int n=s.length();
        unordered_map<char,int> mpp;
        int len=0;
        while(high<n){
            mpp[s[high]]++;
            int k=high-low+1;
            while(mpp.size()<k){
                mpp[s[low]]--;
                if(mpp[s[low]]==0){
                    mpp.erase(s[low]);
                }
                low++;
                k=high-low+1;
            }
            len=max(len,high-low+1);
            high++;
        }
        return len==INT_MIN?0:len;
    }
};
