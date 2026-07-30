class Solution { 
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp,target;
        for(int i=0;i<t.length();i++){
            target[t[i]]++;
        }
        int low=0;
        int high=0;
        int n=s.length();
        int formed=0;
        int required = target.size();
        int start=0;
        int minlen=INT_MAX;
        string res="";
        while(high<n){
            char ch=s[high];
            mpp[ch]++;
            if(target.count(ch) && mpp[ch] == target[ch])
                formed++;
            while(formed==required){
                if(high-low+1<minlen){
                    minlen=min(minlen,high-low+1);
                    start=low;
                }
                char left=s[low];
                mpp[left]--;
                if(target.count(left) && mpp[left]<target[left]){
                    formed--;
                }
                low++;
            }
            high++;
        }
        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    }
};
