class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int start=0;
        int maxLen=0;
        string res="";
        for(int i=0;i<s.length();i++){
            dp[i][i]=true;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(s[i]==s[j] && (len<=3 || dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(len>maxLen){
                        maxLen=len;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};
