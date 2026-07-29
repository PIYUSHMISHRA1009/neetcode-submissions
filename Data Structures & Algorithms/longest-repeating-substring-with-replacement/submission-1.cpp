class Solution {
public:
    int maxf(unordered_map<char,int> &mpp){
        int mx=0;
        for(auto it:mpp){
            mx=max(mx,it.second);
        }
        return mx;
    }
    int characterReplacement(string s, int k) {
        int n=s.length();
        int low=0;
        int high=0;
        int res=0;
        unordered_map<char,int> mpp;
        while(high<n){
            mpp[s[high]]++;
            int maxcnt=maxf(mpp);
            int len=high-low+1;
            int diff=len-maxcnt;
            while(diff>k){
                mpp[s[low]]--;
                if(mpp[s[low]]==0){
                    mpp.erase(s[low]);
                }
                low++;
                maxcnt=maxf(mpp);
                len=high-low+1;
                diff=len-maxcnt;
            }
            res=max(res,high-low+1);
            high++;
        }
        return res;
    }
};
