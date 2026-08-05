class Solution {
public:
    int cntDistinctSubsequences(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int match=0;
        if(s[i]==t[j]){
            match=cntDistinctSubsequences(i-1,j-1,s,t,dp);
        }
        int notmatch=cntDistinctSubsequences(i-1,j,s,t,dp);
        return dp[i][j]=match+notmatch;
    }
    int numDistinct(string s, string t) {
        //memoization
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return cntDistinctSubsequences(n-1,m-1,s,t,dp);
    }
};
