class Solution {
public:
    int numDistinct(string s, string t) {
        //tabulation
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int match=0;
                if(s[i-1]==t[j-1]){
                    match=dp[i-1][j-1];
                }
                int notmatch=dp[i-1][j];
                dp[i][j]=match+notmatch;
            }
        }
        return dp[n][m];
    }
};
