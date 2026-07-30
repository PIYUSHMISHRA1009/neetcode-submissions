class Solution {
public:
    bool check(unordered_map<char,int> &mpp,
        unordered_map<char,int> &target){
            for(auto it:target){
                if(mpp[it.first]<it.second){
                    return false;
                }
            }
            return true;
    }
    string minWindow(string s, string t) {
        //use the padho with pratyush pattern
        int low=0;
        int high=0;
        int n=s.length();
        unordered_map<char,int> mpp,target;
        for(int i=0;i<t.length();i++){
            target[t[i]]++;
        }
        string res="";
        int minwind=INT_MAX;
        while(high<n){
            mpp[s[high]]++;
            while(check(mpp,target)){
                if(high-low+1<minwind){
                    minwind=high-low+1;
                    res=s.substr(low,minwind);
                }
                mpp[s[low]]--;
                if(mpp[s[low]]==0){
                    mpp.erase(s[low]);
                }
                low++;
            }
            high++;
        }
        return res==""?"":res;

    }
};
