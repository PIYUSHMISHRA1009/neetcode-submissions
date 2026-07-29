class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mpp[t[i]]--;
            if(mpp[t[i]]==0){
                mpp.erase(t[i]);
            }
        }
        return mpp.empty();
    }
};
