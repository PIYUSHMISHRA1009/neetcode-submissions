class Solution {
public:
    bool checkInclusion(string s1, string s2) { 
        int low=0;
        int high=0;
        int n=s2.length();
        unordered_map<char,int> mpp,target;
        for(auto it:s1){
            target[it]++;
        }
        while(high<n){
            mpp[s2[high]]++;
            int k=high-low+1;
            while(k>s1.length()){
                mpp[s2[low]]--;
                if(mpp[s2[low]]==0){
                    mpp.erase(s2[low]);
                }
                low++;
                k=high-low+1;
            }
            if (k == s1.length() && mpp == target)
                return true;
            high++;
        }
        return false;
    }
};
